#!/usr/bin/python

import sys
infile = sys.stdin

def solve(Emax, R, E, v):
    if len(v) == 1:
        return E*v[0]
    return max( [ e*v[0] + solve(Emax, R, min(Emax, E-e+R), v[1:])
                  for e in range(E+1) ])
        

T = int(infile.readline())
for t in range(T):
    E, R, N = map(int, infile.readline().split())
    v = map(int, infile.readline().split())

    print 'Case #%d: %d' % (t+1, solve(E, R, E, v))
