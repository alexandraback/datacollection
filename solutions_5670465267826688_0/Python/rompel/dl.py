#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())


# Unit quaternion multiplication in all its glory
# Caps indicate negation 
# N = -1; n = 1
mq = { ("i","j"):"k",
       ("i","k"):"J",
       ("j","i"):"K",
       ("j","k"):"i",
       ("k","i"):"j",
       ("k","j"):"I" }
for i in "ijk":
    mq[(i,i)] = "N"
    mq[(i,"n")] = i
    mq[("n",i)] = i
mq[("n","n")] = "n"
for i in "ijkIJKnN":
    for j in "ijkIJKnN":
        c = mq[(i.lower(), j.lower())]
        mq[(i,j)] = c.swapcase() if i.isupper()^j.isupper() else c

def qmult(x, y):
    return mq[(x,y)]


def qpow(x, n):
    if n==1:
        return x
    if n&1:
        return qmult(x, qpow(x, n-1))
    xx = qpow(x, n//2)
    return qmult(xx, xx)


def solve_one_case():
    (L, X) = rdints()
    q = rdline()
    assert len(q)==L
    ps = {}
    for pp in "ijkIJKnN":
        Z = []
        p = pp
        for x in q:
            p = mq[(p,x)]
            Z.append(p)
        ps[pp] = "".join(Z)
    l = qpow(ps["n"][-1], X)
    if l != "N":
        return "NO1"
    seen = set()
    p = "n"
    i = 0
    while i<X and p not in seen:
        i += 1
        seen.add(p)
        if "i" in ps[p]:
            k = ps[p].find("i")
            if "k" in ps[p][k:]:
                return "YES1"
            seen = set()
            p = ps[p][-1]
            while i<X and p not in seen:
                i += 1
                seen.add(p)
                if "k" in ps[p]:
                    return "YES2"
                p = ps[p][-1]
            return "NO2"
        p = ps[p][-1]
    return "NO3"
    #ans = "YES" if re.match("^.*i.*k.*N$", Z) else "NO"


def do_one_case(cnum):
    ans = solve_one_case()
    print "Case #%d: %s" % (cnum, ans[:-1])



    




def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
