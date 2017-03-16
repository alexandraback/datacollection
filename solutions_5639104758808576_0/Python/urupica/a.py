#!/usr/bin/python

import sys, datetime

# https://code.google.com/p/gmpy/
#import gmpy

def solve(s):
    s = map(int,s)
    n = s[0]
    p = 0
    for i in xrange(1,len(s)):
        if s[i] > 0:
            if i > n:
                p += i-n
                n = i
            n += s[i]
    return p

def main():
    timeStart = datetime.datetime.now()
    (inputFile, outputFile) = openFiles()
    testCases = int(inputFile.readline().strip())
    printHeader(testCases, outputFile)

    for testCaseNumber in xrange(1, testCases+1):
        s = inputFile.readline().strip().split()[1]
        string = 'Case #%d: %d' % (testCaseNumber, solve(s))
        print string
        if outputFile:
            outputFile.write(string + '\n')

    printFooter(outputFile, timeStart)
    closeFiles(inputFile, outputFile)


def openFiles():
    inputFile = open(sys.argv[1])
    outputFile = None
    if len(sys.argv) >= 3:
        outputFile = open(sys.argv[2], 'w')
    return (inputFile, outputFile)


def closeFiles(inputFile, outputFile):
    inputFile.close()
    if outputFile:
        outputFile.close()

def printHeader(testCases, outputFile):
    print '-----------------'
    print 'Test cases: %d ' % testCases
    if outputFile:
        print 'Writing to %s' % sys.argv[2]
    else:
        print 'No output file'
    print '-----------------'

def printFooter(outputFile, timeStart):
    print '-----------------'
    if outputFile:
        print 'Written to %s' % sys.argv[2]
    else:
        print 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timeStart)
    print '-----------------'

if __name__=='__main__':
    main()
