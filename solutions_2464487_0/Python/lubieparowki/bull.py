import os, sys
from pprint import *

inFile = None
outFile = None


def printAnswer(case, answer):
    outFile.write('Case #{0}: {1}\n'.format(case+1, answer))

def solveCase(caseNo):
    (r,t) = map(int, inFile.readline().strip().split())
    ans = ''
    sum = 0
    a = 2*r + 1
    (l,r) = (1, t)
    while l < r:
        m = (l+r)/2
        sum = ((2*a + (m-1)*4)*m)/2
        if sum > t:
            r = m
        else:
            l = m + 1

    printAnswer(caseNo, l-1)

def main():
    cases = int(inFile.readline().strip())
    for case in range(cases):
        solveCase(case)

if __name__ == '__main__':
    inFile = open('in.txt','rt')
    outFile = open('out.txt', 'wt')
    main()