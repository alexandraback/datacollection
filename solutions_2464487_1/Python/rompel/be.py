#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())



def paint(r, n):
    return 2*n*n + (2*r-1)*n

def do_one_case(cnum):
    r,t = rdints()

    a = 2.0
    b = 2*r - 1.0
    c = -1.0*t
    x = (math.sqrt(b*b-4.0*a*c)-b)/(2.0*a)
    n = math.floor(x)
    while paint(r, n)>t:
        n -= 1
    while paint(r, n+1)<=t:
        n += 1
    print "Case #%d: %d" % (cnum, n)


def main():
    N = int(rdline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
