#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())



def do_one_case(cnum):
    (E, R, N) = rdints()
    v = rdints()
    assert len(v)==N
    NN = 99*(N + E + R)
    e = E
    y = 0
    for i in range(N):
        vi = v[i]
        k = min([NN] + [ j for j in range(i+1,N) if v[j]>vi ])
        s = min(e, max(0, e+(k-i)*R-E))
        y += s*vi
        e = min(E, e-s+R)
    assert e==min(E, R)
    print "Case #%d: %d" % (cnum, y)







def main():
    N = int(rdline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
