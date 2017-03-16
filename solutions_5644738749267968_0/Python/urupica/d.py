#!/usr/bin/python

import sys, datetime

def deceitfulWar(a, b):
    c = 0
    while a:
        if max(a) > max(b):
            a.remove(min(filter(lambda x:x>b[0], a)))
            b.pop(0)
            c += 1
        else:
            a.pop(0)
            b.pop()
    return c


def war(a, b):
    c = 0
    while a:
        n = len(a)
        m = len(b)
        k = n/2
        if a[k] > b[-1]:
            s = filter(lambda i:a[i]<b[0], xrange(n))
            j = max(s) if s else -1
            c += n-k
            a = a[j+1:k]
            b.pop(0)
        else:
            j = min(filter(lambda i:a[k]<b[i], xrange(m)))
            a = a[:k] + a[k+1:]
            b = b[:j] + b[j+1:]
    return c


def solve(a, b):
    a = sorted(a)
    b = sorted(b)
    return '%d %d' % (deceitfulWar(list(a), list(b)), war(a, b))


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

        n = int(inputFile.readline().strip())
        a = map(float, inputFile.readline().strip().split())
        b = map(float, inputFile.readline().strip().split())

        string = 'Case #%d: %s' % (testCaseNumber, solve(a, b))

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
