#!/usr/bin/python

import sys, datetime

count = None

def minimize(s):
    ss = ''
    for x in s:
        if not ss or x != ss[-1]:
            ss += x
    return ss

def isValid(s):
    for x in s:
        if s.count(x) > 1:
            return False
    return True

def areValid(s,t):
    for i,x in enumerate(s[1:-1]):
        if x in (s[0],s[-1]):
            continue
        if x in t:
            return False
    for i,x in enumerate(t[1:-1]):
        if x in (t[0],t[-1]):
            continue
        if x in x:
            return False
    return True





def search(train, cars):
    global count
    if not cars:
        count += 1
        return
    for i,c in enumerate(cars):
        t = train+c
        t = minimize(t)
        if isValid(t):
            valid = True
            for x in cars[:i]+cars[i+1:]:
                if not areValid(t,x):
                    valid = False
                    break
            if valid:
                search(t,cars[:i]+cars[i+1:])

def solve(n, cars):
    global count
    cars2 = []
    for c in cars:
        cars2.append(minimize(c))
    cars = cars2
    for i,c in enumerate(cars):
        if len(c) > 2:
            for x in c[1:-1]:
                if x in (c[0],c[-1]):
                    continue
                for d in cars[:i] + cars[i+1:]:
                    if x in d:
                        return 0
    count = 0
    for i,c in enumerate(cars):
        search(c, cars[:i]+cars[i+1:])

    return count % 1000000007




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
        cars = inputFile.readline().strip().split()

        string = 'Case #%d: %d' % (testCaseNumber, solve(n, cars))

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
