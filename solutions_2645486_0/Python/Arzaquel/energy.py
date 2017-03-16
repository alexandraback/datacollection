from __future__ import print_function, division

import sys, math
from decimal import *
import itertools

infile = open(sys.argv[1])
outfiles = (sys.stdout, open(sys.argv[2], 'w'))

def chunks(l, n):
    for i in range(0, len(l), n):
        yield l[i:i+n]

def read_in(infile):
    data = infile.readlines()
    amount = int(data[0])
    #content = list(grouper(2,[s.strip() for s in data[1:]]))
    content = list(chunks([s.strip() for s in data[1:]],2))
    assert amount == len(content)
    return content

def do_output(number, output, outfiles):
    for f in outfiles:
        print('Case #%d:' % number, output, file=f)

def main():
    for i, content in enumerate(read_in(infile)):
        do_output(i+1, do_task(content), outfiles)

def do_task(content):
    # Parse input string
    meta = [int(x) for x in content[0].split()]
    tasks = [int(x) for x in content[1].split()]
    origtasks = [x for x in tasks]
    spend = [0 for x in tasks]
    maxe = [meta[0] for x in tasks]
    needed = [0 for x in tasks]

    for i in range(0, len(tasks)):
        best = -1
        besti = -1
        for j in range(0, len(tasks)):
            if(tasks[j] > best):
                best = tasks[j]
                besti = j
        j = besti
        spend[j] = maxe[j] - needed[j]
        tasks[j] = -1
        newmaxe = meta[1]
        req = maxe[j] - meta[1]
        j = j+1 
        while(newmaxe < meta[0] and j < len(tasks)):
            maxe[j] = newmaxe
            newmaxe = newmaxe + meta[1]
            j = j+1
        j = besti - 1
        while(req > 0 and j >= 0):
            needed[j] = req
            req = req - meta[1]
            j = j-1
    total = 0
    for i in range(0, len(tasks)):
        total = total + max(0, spend[i]) * origtasks[i]
    return total

if __name__=='__main__':
    getcontext().prec = 50
    main()



#[path: D:\app\hanzures\product\11.2.0\dbhome_1\bin;C:\windows\system32;C:\windows;C:\windows\System32\Wbem;
#C:\windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\ThinkPad\Bluetooth Software\;C:\Program Files\ThinkPad\Bluetooth Software\syswow64;
#C:\Program Files\Broadcom\WHL\;C:\Program Files\Broadcom\WHL\syswow64;C:\Program Files\Broadcom\WHL\SysWow64\;C:\Program Files\Broadcom\WHL\SysWow64\syswow64;C:\Program Files\TortoiseSVN\bin;C:\MinGW\bin]