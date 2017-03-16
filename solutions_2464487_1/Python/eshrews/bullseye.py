#!/usr/bin/python

import fileinput

case = 1
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue

    l = [int(x) for x in line.split()]
    r = l[0]
    t = l[1]
    result = 0
    paint = (r + 1)**2 - (r)**2


    def getp(cir):
        return (paint) * (cir) + (2 * ((cir) * (cir - 1)))

        
    if getp(1) == t:
        result = 1
    elif getp(1) < t:
        testRange = 2
        while getp(testRange) < t:
            testRange *= 2

        rangel = testRange / 2
        rangeh = testRange
        found = False
        while(rangeh - rangel > 100):
            test = (rangel + rangeh) / 2
            p = getp(test)
            if p <= t:
                rangel = test
            else:
                rangeh = test

        for test in xrange(rangel, rangeh+1):
            if getp(test) <= t:
                result = test

    print "Case #{0}: {1}".format(linenum, result)
