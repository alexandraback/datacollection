#!/usr/bin/python

import sys, datetime

mi = None
visited = None

def search(w,s):
    global mi,visited
    t = (w,) + tuple(sorted((x,s[x]) for x in filter(s.get, s)))
    if t in visited:
        return
    visited.add(t)
    m = max(filter(lambda x:s[x] > 0,s))
    if m+w < mi:
        mi = m+w
    if m == 1:
        return
    for a in xrange(2,m/2+1):
        s2 = dict(s)
        b = m-a
        s2[m] -= 1
        s2[a] += 1
        s2[b] += 1
        search(w+1,s2)

def solve(d,p):
    global mi,visited
    mi = max(p)
    visited = set()
    s = {x:0 for x in xrange(1,mi+1)}
    for x in p:
        s[x] += 1
    search(0,s)
    return mi

def main():
    timeStart = datetime.datetime.now()
    (inputFile, outputFile) = openFiles()
    testCases = int(inputFile.readline().strip())
    printHeader(testCases, outputFile)

    for testCaseNumber in xrange(1, testCases+1):
        d = int(inputFile.readline().strip())
        p = map(int, inputFile.readline().strip().split())
        string = 'Case #%d: %d' % (testCaseNumber, solve(d,p))
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
