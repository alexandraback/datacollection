#!/usr/bin/python

import sys, time
from math import sqrt
from gmpy import is_square

count = None

def search(coeffs, a, b):
    global count

    coeffsCopy = list(coeffs)
    coeffsCopy.reverse()

    coeffsComplete = coeffs + coeffsCopy
    pal = 0
    for i, n in enumerate(coeffsComplete):
        pal += n * 10**i
    
    keepSearching = True if pal <= b else False

    if a <= pal <= b:
        test = True
        for l in range(len(coeffsComplete)):
            if sum([coeffsComplete[i]*coeffsComplete[l-i] for i in range(l+1)]) > 9:
                test = False
                break
        if test:
            count += 1

    pal = 0
    for i, n in enumerate(coeffs):
        pal += n * (10**i + 10**(2*len(coeffs)-i))


    for x in range(4):
        if a <= pal + x * 10**len(coeffs) <= b:
            coeffsComplete = coeffs + [x] + coeffsCopy
            test = True
            for l in range(len(coeffsComplete)):
                if sum([coeffsComplete[i]*coeffsComplete[l-i] for i in range(l+1)]) > 9:
                    test = False
                    break
            if test:
                count += 1
    
    if keepSearching:
        for x in range(4):
            if not coeffs and x == 0:
                continue
            search(coeffs + [x], a, b)


def solve(a,b):
    global count

    aSqrt = int(sqrt(a)) if is_square(a) else int(sqrt(a)) + 1
    bSqrt = int(sqrt(b))

    count = 0
    search([], aSqrt, bSqrt)
    return count



def main():
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = time.time()
    inputFile = open(sys.argv[1])
    outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    testCases = int(inputFile.readline().strip())
    print '-----------------'
    print 'Test cases: %d ' % testCases
    if len(sys.argv) < 3:
        print 'No output file'
    print '-----------------'
    for testCaseNumber in range(1, testCases+1):

        a, b = [int(xx) for xx in inputFile.readline().strip().split()]

        string = 'Case #%d: %d' % (testCaseNumber, solve(a,b))

        print string
        if outputFile:
            outputFile.write(string + '\n')
    print '-----------------'
    if outputFile:
        outputFile.close()
        print 'Written to',sys.argv[2]
    else:
        print 'No output file'
    print 'Elapsed time: %.3f seconds' % (time.time()-timestart)
    print '-----------------'

if __name__=='__main__':
    main()
