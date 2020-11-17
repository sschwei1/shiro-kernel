#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "io/Terminal.hpp"
#include "io/SerialIo.hpp"
#include "utils/util.hpp"
#include "shells/IShell.hpp"
#include "shells/ComShell.hpp"

extern "C"
{
    int _entry(void)
    {
        Terminal ctx;
        SerialPort serial = SerialPort(serialPort::COM1).initSerial();
        serial.write((const unsigned char*)"[Shiro] Initialized COM1 Serial connection\r\n");

        ctx.setBgColor(vgaTerminalColor::VGA_COLOR_WHITE)
            .setFgColor(vgaTerminalColor::VGA_COLOR_BLACK)
            .clear();

        char test[5];
        itoa(1234, test, 4);

        ctx.setFgColor(vgaTerminalColor::VGA_COLOR_GREEN)
            .printLine("[Shiro] Shiro Kernel initialized\0")
            .printLine("OIDA")
            .printLine(test)
            .printLine("Lmao");


        ComShell shell = ComShell(&serial);
        shell.writeLine("[Shiro] Initialized Shell on COM1");
        shell.runShell();

        return 0;
    }
}