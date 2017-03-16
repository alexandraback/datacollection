#!/usr/bin/env python

import sys

def R(f):
    with open(f,"r") as fin:
        return fin.read().splitlines()

def solve(N):
    if N == 0:
        return "INSOMNIA"

    st = set()
    k = 1
    while True:
        i = k * N
        while i > 0:
            st.add(i%10)
            i /= 10

        if len(st) >= 10:
            return k * N
        
        k += 1


if len(sys.argv) != 2:
    print "usage: %s input_file" % sys.argv[0]
    exit()


Ns = R(sys.argv[1])

T = int(Ns[0])

for i in xrange(1, T+1):
    k = int(Ns[i])
    print "Case #%d:" %i, solve( k )

