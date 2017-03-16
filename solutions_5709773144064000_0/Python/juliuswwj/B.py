#!/usr/bin/python


import sys, io

def run(C, F, X):
    p = 2
    t = 0
    mm = X / p
    while t < mm:
        t += C / p
        p += F
        v = t + X / p
        if v < mm: mm = v
    return mm


T = int(sys.stdin.readline())
for t in range(T):
    C,F,X = map(float, sys.stdin.readline().split())
    print 'Case #%d: %f' % (t+1, run(C, F, X))
    
    