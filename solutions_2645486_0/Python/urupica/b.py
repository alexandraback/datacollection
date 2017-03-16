#!/usr/bin/python

import sys, datetime

e = r = n = None

def solve(a, b, v):
    if not v:
        return 0
    maxV = max(v)
    i = v.index(maxV)
    return solve(a, min(a+i*r, e), v[:i]) + v[i] * (min(a+i*r, e) - max(b-(len(v)-i)*r, 0)) + solve(max(b-(len(v)-i-1)*r , r), b, v[i+1:])
    

def main():
    global e, r, n
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

        e,r,n = map(int, inputFile.readline().strip().split())
        activities = map(int, inputFile.readline().strip().split())

        string = 'Case #%d: %d' % (testCaseNumber, solve(e, 0, activities))

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
