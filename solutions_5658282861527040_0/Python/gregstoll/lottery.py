#!/usr/bin/python
import os, sys, math, itertools

def bits(x):
    return [int(y) for y in bin(x)[2:]][::-1]

# used to generate alllotterynums.txt
def generate():
    for a in range(0,1001):
        for b in range(0,1001):
            print a, b, a&b

lines = []
def solve(a, b, k):
    if len(lines) == 0:
        for line in open('alllotterynums.txt').readlines():
            [a1, b1, k1] = [int(x) for x in line.split(' ')]
            lines.append((a1, b1, k1))
    total = 0
    for l in lines:
        if l[0] < a and l[1] < b and l[2] < k:
            total += 1
    return total

def solveReal(a, b, k):
    aBits = bits(a)
    print aBits
    bBits = bits(b)
    kBits = bits(k)

    # sloooow
    total = 0
    for k1 in range(1, k):
        k1Bits = bits(k1)
        if k1 >= a-1 or k1 >= b-1:
            return total
        for b in range(len(k1Bits)):
            pass



    return total

def main(filename):
    #generate()
    #return
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        (a, b, k) = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        answer = solve(a, b, k)
        print "Case #%d: %d" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
