#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())



def do_one_case(cnum):
    print "Case #1:"
    (R, N, M, K) = rdints()
    parts = gen_parts(N, M, K)
    for i in range(R):
        x = rdints()
        assert len(x)==K
        mp = 0
        bp = None
        for p in parts:
            pr = prob(p, x)
            if pr>mp:
                mp = pr
                bp = p
        print_part(bp)


def gp1(x, k, n):
    if k==0:
        if n==0:
            return [x]
        else:
            return []
    l = []
    for i in range(n+1):
        l += gp1(x+[i], k-1, n-i)
    return l

def gen_parts(N, M, K):
    l = gp1([], M-1, N)
    ll = []
    for p in l:
        pp = list(enumerate(p, 2))
        d = {}
        add_ways(d, 1, 1, pp)
        p0 = .5**N
        for i in d:
            d[i] *= p0
        ll.append((p,d))
    return ll

def add_ways(d, prod, ways, p):
    if len(p)==0:
        if prod in d:
            d[prod] += ways
        else:
            d[prod] = ways
        return

    (n, k) = p[0]
    w = ways
    for i in range(k+1):
        add_ways(d, prod, w, p[1:])
        prod *= n
        w *= (k-i)
        w /= (i+1)
    return

        
def prob(p, x):
    pr = 1
    d = p[1]
    for y in x:
        if y in d:
            pr *= d[y]
        else:
            pr = 0
            break
    return pr


def print_part(p):
    pp = p[0]
    s = ""
    for i in range(len(pp)):
        s += pp[i]*str(i+2)
    print s

        

def main():
    N = int(rdline())
    assert N==1
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
