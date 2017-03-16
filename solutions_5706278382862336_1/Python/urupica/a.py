#!/usr/bin/python

import sys, datetime

# https://code.google.com/p/gmpy/
from gmpy import sqrt

from fractions import Fraction as frac


def solve(pq):
    start = (frac(pq[0], pq[1]), 0)
    n = 0
    y = start[0].denominator
    while y % 2 == 0:
        n += 1
        y /= 2
    if y != 1:
        return 'impossible'

    q = [start]
    v = set([start])
    while q:
        t,g = q.pop()
        if g >= 40:
            return 'impossible'
        anc = set()
        x = t.numerator
        y = t.denominator
        n = 0
        while y % 2 == 0:
            n += 1
            y /= 2
        i = 0
        n2 = n/2
        xx = 2*x
        while i <= n2:
            b = 2**i
            d = 2**(n-i)
            a = 0
            ad = a*d
            while ad <= xx:
                if (xx-ad) % b == 0:
                    c = (xx-ad)/b
                    t1 = frac(a,b)
                    t2 = frac(c,d)
                    if t1 == 1 or t2 == 1:
                        return g+1
                    anc.add((t1, g+1))
                    anc.add((t2, g+1))
                a += 1
                ad = a*d
            i += 1
        for u in anc:
            if u not in v:
                v.add(u)
                q.insert(0,u)


def main():
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = datetime.datetime.now()

    try:
        inputFile = open(sys.argv[1])
    except:
        print 'Failed to read input file %s' % sys.argv[1]
        return
    try:
        outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    except:
        print 'Failed to create output file %s' % sys.argv[2]
        return

    testCases = int(inputFile.readline().strip())

    print '-----------------'
    print 'Test cases: %d ' % testCases
    print 'No output file' if len(sys.argv) < 3 else 'Writing to %s' % sys.argv[2]
    print '-----------------'

    for testCaseNumber in range(1, testCases+1):

        pq = map(int, inputFile.readline().strip().split('/'))

        string = 'Case #%d: %s' % (testCaseNumber, solve(pq))

        print string
        if outputFile:
            outputFile.write(string + '\n')

    print '-----------------'
    print 'Written to %s' % sys.argv[2] if outputFile else 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

    inputFile.close()
    if outputFile:
        outputFile.close()

if __name__=='__main__':
    main()
