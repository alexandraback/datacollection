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
    S = rdline()
    print "Case #%d: %s" % (cnum, lastword(S))


def lastword(S):
    if not S:
        return ""
    c = max(S)
    n = S.count(c)
    i = S.find(c)
    x = n*c + lastword(S[:i]) + S[i:].replace(c,"")
    return x

def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
