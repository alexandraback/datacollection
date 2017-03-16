#!/usr/bin/env python

import sys

def R(f):
    with open(f,"r") as fin:
        return fin.read().splitlines()

def solve_small(line):
    K,C,S = map(int, line.split())
    if S < K:
        return "IMPOSSIBLE"

    Base = K ** (C-1)
    res = [ 1 + Base * i for i in xrange(K) ]
    return " ".join([str(x) for x in res])


def solve(line):
    K,C,S = map(int, line.split())

    p = 0
    ans = []
    for _ in xrange(S):
        i = 0
        for _ in xrange(C):
            if p < K:
                i = i*K + p
                p += 1
            else:
                i *= K

        #print "i=%d, p=%d" % (i,p)
        ans.append(i)

        if p== K:
            break

    if p < K:
        return "IMPOSSIBLE"

    return " ".join([str(x+1) for x in ans ])


if len(sys.argv) != 2:
    print "usage: %s input_file" % sys.argv[0]
    exit()


ss = R(sys.argv[1])

T = int(ss[0])

for i in xrange(1, T+1):
    print "Case #%d:" %i, solve( ss[i] )

