#!/usr/bin/python

import sys
infile = sys.stdin
#infile = open('in.txt', 'r')

def level(E, R, k):
    if (k%2) == 0:
        return R*k/2
    return (E%R) + R*(k-1)/2

def index(E, R, energy):
    v = 2*(energy/R)
    if (energy % R) == 0:
        return v
    return v+1

def solve(E, R, v):
    R = min(R, E)
    nlevels = 2 * (E/R + 1)

    prev = [ v[-1] * level(E, R, k) for k in range(nlevels) ]

    for i in range(1, len(v)):
        col = []
        energy = 0
        best = 0

        val = v[-(i+1)]

        for j in range(nlevels):
            en = level(E, R, j)
            ee = en - energy
            energy = en
            best = max(best + val*ee, prev[min(j+2, nlevels-1)])
            col.append(best)
        
        #print col
        prev = col
        
    return max(prev)
            

T = int(infile.readline())
for t in range(T):
    E, R, N = map(int, infile.readline().split())
    v = map(int, infile.readline().split())

    print 'Case #%d: %d' % (t+1, solve(E, R, v))
