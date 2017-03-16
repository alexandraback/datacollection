#!/usr/bin/python

import sys, datetime

def sign(n):
    return 1 if n > 0 else -1

def mult(a,b):
    if abs(a) == 1 or abs(b) == 1:
        return a*b
    elif abs(a) == abs(b):
        return -sign(a*b)
    elif abs(a) == 2 and abs(b) == 3:
        return 4*sign(a*b)
    elif abs(a) == 3 and abs(b) == 4:
        return 2*sign(a*b)
    elif abs(a) == 4 and abs(b) == 2:
        return 3*sign(a*b)
    elif abs(a) == 3 and abs(b) == 2:
        return -4*sign(a*b)
    elif abs(a) == 4 and abs(b) == 3:
        return -2*sign(a*b)
    else:
        return -3*sign(a*b)


def solve(l,x,s):
    if len(set(s)) == 1:
        return 'NO'
    s = map(lambda z:2 if z == 'i' else 3 if z == 'j' else 4, s)
   
    i = 0
    c = 1
    for k in (2,3):
        j = i
        n = 1
        while n != k and c <= x:
            n = mult(n,s[i])
            i = (i+1)%l
            if i == 0:
                c += 1
            if i == j and n == 1:
                break
        if n != k:
            return 'NO'
    r = 1
    if i > 0:
        while i < l:
            r = mult(r,s[i])
            i += 1
        c += 1
    n = 1
    if c <= x:
        for i in xrange(l):
            n = mult(n,s[i])
        j = (x-c+1)%4
        if j == 0:
            n = 1
        elif j == 2:
            if abs(n) == 1:
                n = 1
            else:
                n = -1
        elif j == 3:
            if abs(n) > 1:
                n = -n
    n = mult(r,n)
    return 'YES' if n == 4 else 'NO'

def main():
    timeStart = datetime.datetime.now()
    (inputFile, outputFile) = openFiles()
    testCases = int(inputFile.readline().strip())
    printHeader(testCases, outputFile)

    for testCaseNumber in xrange(1, testCases+1):
        l,x = map(int, inputFile.readline().strip().split())
        s = inputFile.readline().strip()
        string = 'Case #%d: %s' % (testCaseNumber, solve(l,x,s))
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
