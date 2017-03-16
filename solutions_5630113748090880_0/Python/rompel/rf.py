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
    s = []
    ss = []
    for i in range(2*N-1):
        v = rdints()
        assert len(v)==N
        s.append(v)
        ss.append(set(v))
    for i in range(N):
        v = [ x[i] for x in s ]
        v.sort()
        vs = set(v)
        if i==N-1 or v[2*i]<v[2*i+1]:
            z = v[2*i]
            assert i==0 or v[2*i-1]<v[2*i]
            ul = [ x for x in s if x[i]==z ]
            assert len(ul)==1
            u = ul[0]
            for x in u:
                if x!=z:
                    del v[v.index(x)]
            w = " ".join(map(str,v))
            print "Case #%d: %s" % (cnum, w)
            return
    #s.sort()
    #if s[0][0]==s[1][0]:
    #    pass
    #else:
    #    pass


def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
