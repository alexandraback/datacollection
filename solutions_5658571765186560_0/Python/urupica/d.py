#!/usr/bin/python

import sys, datetime

def solve(x,r,c):
    r,c = min(r,c),max(r,c)
    if x == 1:
        return 'GABRIEL'
    if x == 2:
        if r == 1:
            if c % 2 == 1:
                return 'RICHARD'
            else:
                return 'GABRIEL'
        elif r == 2:
            return 'GABRIEL'
        elif r == 3:
            if c == 3:
                return 'RICHARD'
            else:
                return 'GABRIEL'
        else:
            return 'GABRIEL'
    elif x == 3:
        if r == 1:
            return 'RICHARD'
        elif r == 2:
            if c  == 3:
                return 'GABRIEL'
            else:
                return 'RICHARD'
        elif r == 3:
            return 'GABRIEL'
        else:
            return 'RICHARD'
    else:
        if r <= 2:
            return 'RICHARD'
        elif r == 3:
            if c == 3:
                return 'RICHARD'
            else:
                return 'GABRIEL'
        else:
            return 'GABRIEL'


def main():
    timeStart = datetime.datetime.now()
    (inputFile, outputFile) = openFiles()
    testCases = int(inputFile.readline().strip())
    printHeader(testCases, outputFile)

    for testCaseNumber in xrange(1, testCases+1):
        x,r,c = map(int, inputFile.readline().strip().split())
        string = 'Case #%d: %s' % (testCaseNumber, solve(x,r,c))
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
