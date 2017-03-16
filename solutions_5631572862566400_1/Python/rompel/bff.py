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
    B = rdints()
    assert len(B)==N
    B = [ b-1 for b in B ]
    mcy = 0
    cl = []
    t = {}
    for i in range(N):
        j = B[i] 
        l = [i]
        s = set(l)
        while j not in s:
            l.append(j)
            s.add(j)
            j = B[j]
        if j==i:
            mcy = max(mcy, len(l))
        if j==l[-2]:
            tp = tuple(sorted(l[-2:]))
            if tp not in t:
                t[tp] = []
            t[tp].append((len(l), i, l))
        cl.append(l)
    mch = 0
    for k,v in t.iteritems():
        v1 = [ (l, x, y) for (l, x, y) in v if y[-1]==k[0] ]
        v2 = [ (l, x, y) for (l, x, y) in v if y[-1]==k[1] ]
        assert len(v1)+len(v2)==len(v)
        l1, x, y = max(v1)
        l2, x, y = max(v2)
        mch += l1 + l2 - 2
    print "Case #%d: %d" % (cnum, max(mcy, mch))



    




def bffs(B, a):
    l = [ a,  ]
    s = set(l)
    r = set(B) - s


def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
