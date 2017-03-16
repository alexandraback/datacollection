#!/usr/bin/env python
import sys
from fractions import Fraction

case_num = 1
def printres(result):
    global case_num
    print "Case #%s: %s" % (case_num, result)
    case_num += 1

def readline(): 
    return sys.stdin.readline().rstrip('\n')
def splitline(f):
    return map(f, readline().split())


def solve():
    P, Q = readline().split('/')
    f = Fraction(int(P),int(Q))
    gen = -1
    for i in range(40):
        if f >= Fraction(1,2**i):
            f = f - Fraction(1,2**i)
            if gen < 0:
                gen = i
    if f != 0:
        printres('impossible')
    else:
        printres(gen)

def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

