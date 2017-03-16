#!/usr/bin/python

import sys, datetime
from gmpy import sqrt

def solve(r, t):
    #return int(1.0/4-float(r)/2+sqrt((1.0/4-float(r)/2)**2+float(t)/2))
    n = int(1-2*r+sqrt((1-2*r)**2+8*t))/4
    print '%d, %d, %d' % (2*n**2+(2*r-1)*n, t, 2*(n+1)**2+(2*r-1)*(n+1))
    return n


def main():
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = datetime.datetime.now()
    inputFile = open(sys.argv[1])
    outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    testCases = int(inputFile.readline().strip())
    print '-----------------'
    print 'Test cases: %d ' % testCases
    if len(sys.argv) < 3:
        print 'No output file'
    print '-----------------'
    for testCaseNumber in range(1, testCases+1):

        r, t = map(int, inputFile.readline().strip().split())

        string = 'Case #%d: %d' % (testCaseNumber, solve(r, t))

        print string
        if outputFile:
            outputFile.write(string + '\n')
    print '-----------------'
    if outputFile:
        outputFile.close()
        print 'Written to',sys.argv[2]
    else:
        print 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

if __name__=='__main__':
    main()
