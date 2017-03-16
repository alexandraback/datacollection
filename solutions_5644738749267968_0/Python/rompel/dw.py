#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction
from bisect import bisect_left

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())
def rdfloats(): return map(float, ssr().split())
def rd1int(): return int(rdline())



def do_one_case(cnum):
    n = rd1int()
    N0 = sorted(rdfloats())
    K0 = sorted(rdfloats())
    assert len(N0)==n
    assert len(K0)==n

    N = list(reversed(N0))
    w1 = 0
    for b in reversed(K0):
        if b>N[0]:
            del N[-1]
        else:
            del N[0]
            w1 += 1

    K = K0
    w2 = 0
    for a in N0:
        if a > K[-1]:
            del K[0]
            w2 += 1
        else:
            del K[bisect_left(K, a)]

    print "Case #%d: %d %d" % (cnum, w1, w2)




    




def main():
    N = rd1int()
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
