#!/usr/bin/env python

import sys

def R(f):
    with open(f,"r") as fin:
        return fin.read().splitlines()

S = None

def solve(N):
    if N == 0:
        return ''

    x = S[0]
    index = -1
    for i in xrange(N):
        if S[i] >= x:
            x = S[i]
            index = i

    return x + solve(index) + S[index+1:N]


if len(sys.argv) != 2:
    print "usage: %s input_file" % sys.argv[0]
    exit()


ss = R(sys.argv[1])

T = int(ss[0])

for i in xrange(1, T+1):
    S = ss[i]
    print "Case #%d:" %i, solve( len(S) )

