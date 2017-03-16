#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction, gcd

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())

P = [2]
px = 2
for i in range(3,10000,2):
    if all(i%j for j in P):
        P.append(i)
        px *= i




def do_one_case(cnum):
    N, J = rdints()
    n2 = N-2

    d = [None,None] + [ [ b**(i+1) for i in range(n2) ] for b in range(2,11) ]
    e = [None,None] + [ 1 + b**(N-1) for b in range(2,11) ]
    i = n = 0
    ni = 2**n2
    print "Case #1:"
    while n<J and i<ni:
        prime = False
        l = []
        for b in range(2,11):
            x = e[b] + sum(d[b][j] for j in range(n2) if i&(1<<j))
            g = gcd(px,x)
            if g==1:
                prime = True
                break
            elif g<x:
                l.append(g)
                continue
            # Handle non-trivial factor, only needed for sample input
            for p in P:
                if not x%p:
                    l.append(p)
                    break
        if not prime:
            l2 = [x] + l
            print " ".join(map(str,l2))
            n += 1
        #else:
        #    print "psuedo-prime", i
        i += 1
    assert n==J


def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
