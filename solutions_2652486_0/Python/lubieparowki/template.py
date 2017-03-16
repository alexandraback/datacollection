import os, sys
import math
from pprint import *

inFile = None
outFile = None


def printAnswer(case, answer):
    outFile.write('Case #{0}: {1}\n'.format(case+1, answer))


def solveSet(R, N, M, K, SET):
    for a in range(2, M+1):
        for b in range(2, M+1):
            for c in range(2, M+1):
                good = True
                v = [a, b, c, a*b, b*c, a*c, a*b*c, 1]
                print a,b,c
                for k in SET:
                    if k not in v:
                        good = False
                        break

                if good:
                    return [a,b,c]

    return [2,2,2]


def solveCase(caseNo):
    (R, N, M, K) = map(int, inFile.readline().strip().split())

    printAnswer(caseNo, '')
    for r in range(R):
        V = map(int, inFile.readline().strip().split())
        s = ''.join(map(str, solveSet(R, N, M, K, V)))
        outFile.write(s+'\n')
        # print s


    

def main():
    cases = int(inFile.readline().strip())
    for case in range(cases):
        solveCase(case)

if __name__ == '__main__':
    inFile = open('in.txt','rt')
    outFile = open('out.txt', 'wt')
    main()