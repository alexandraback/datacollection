#!/usr/bin/python

import sys, datetime
# https://code.google.com/p/gmpy/
from gmpy import mpf


def solve(c, f, x):
    t1 = x/2
    f1 = k = 0
    while True:
        k += 1
        f2 = f1 + c/(2+(k-1)*f)
        t2 = f2 + x/(2+k*f)
        if t2 >= t1:
            return t1
        t1, f1= t2, f2

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

        c, f, x = map(lambda x: mpf(x), map(float, inputFile.readline().strip().split()))

        string = 'Case #%d: %.7f' % (testCaseNumber, solve(c, f, x))

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
