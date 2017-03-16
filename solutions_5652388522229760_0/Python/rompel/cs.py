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
    N = rd1int()
    if N==0:
        print "Case #%d: INSOMNIA" % (cnum,)
        return
    assert N>0
    seen = 10*[False]
    n = 0
    while not all(seen):
        n += N
        m = n
        while m:
            d = m%10
            seen[d] = True
            m /= 10
    print "Case #%d: %d" % (cnum, n)


def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
