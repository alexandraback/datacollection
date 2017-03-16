#!/usr/bin/python

import fileinput

case = 0
A, N = 0, 0
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue
    
    if linenum % 2 == 1:
        case += 1
        an = [int(x) for x in line.split()]
        A = an[0]
        N = an[1]
        continue

    motes = [int(x) for x in line.split()]
    motes.sort()

    size = A
    result = len(motes)
    ops = 0

    for i, mote_size in enumerate(motes):
        if size > mote_size:
            size += mote_size
        else:
            left = len(motes) - i
            result = min(ops+left, result)
            extra = 0
            while (size <= mote_size and extra <= result):
                size += size - 1
                extra += 1
            size += mote_size
            ops += extra

    result = min(result, ops)

    print "Case #{0}: {1}".format(case, result)

    if case == cases:
        break
