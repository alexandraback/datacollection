from __future__ import print_function, division

import sys, math
from decimal import *

infile = open(sys.argv[1])
outfiles = (sys.stdout, open(sys.argv[2], 'w'))

def read_in(infile):
    data = infile.readlines()
    amount = int(data[0])
    content = data[1:]
    assert amount == len(content)
    return [s.strip() for s in content]

def do_output(number, output, outfiles):
    for f in outfiles:
        print('Case #%d: ' % number, output, file=f)

def main():
    for i, content in enumerate(read_in(infile)):
        do_output(i+1, do_task(content), outfiles)

def do_task(content):
    # Parse input string

    numbers = [int(x) for x in content.split()]
    b = (2*numbers[0] - 1)
    return  int((Decimal(b*b + 8*numbers[1]).sqrt() - b)/4)

if __name__=='__main__':
    getcontext().prec = 50
    main()

#[path: D:\app\hanzures\product\11.2.0\dbhome_1\bin;C:\windows\system32;C:\windows;C:\windows\System32\Wbem;
#C:\windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\ThinkPad\Bluetooth Software\;C:\Program Files\ThinkPad\Bluetooth Software\syswow64;
#C:\Program Files\Broadcom\WHL\;C:\Program Files\Broadcom\WHL\syswow64;C:\Program Files\Broadcom\WHL\SysWow64\;C:\Program Files\Broadcom\WHL\SysWow64\syswow64;C:\Program Files\TortoiseSVN\bin;C:\MinGW\bin]