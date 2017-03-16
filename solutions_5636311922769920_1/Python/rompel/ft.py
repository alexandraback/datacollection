#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())



def do_one_case(cnum):
    K, C, S = rdints()
    if S*C<K:
        print "Case #%d: IMPOSSIBLE" % (cnum,)
        return
    x = [ "Case #%d:" % (cnum,) ]
    for i in range(0, K, C):
        n = 0
        for j in range(i, min(i+C, K)):
            n = K*n + j
        x.append(str(n+1))
    print " ".join(x)


def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
