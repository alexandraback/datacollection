#!/usr/bin/env python
# coding: utf-8

import sys

def opt1(A, B, P):
    pright = 1.0;
    for i in range(A):
        pright *= P[i];
    Ex = (B-A+1) + (B+1) * (1-pright)
    return Ex;

def opt2(A, B, P):
    minEx = B+2;
    for i in range(A+1):
        Ex = opt1(A-i, B, P) + i;
        minEx = min(Ex, minEx);
    return minEx;

with open(sys.argv[1]) as infile:
    inlines = [line.strip() for line in infile][1:];
    T = len(inlines)/2;
    for i in range(T):
        A = int(inlines[i*2].split()[0]);
        B = int(inlines[i*2].split()[1]);
        P = [float(p) for p in inlines[i*2+1].split()];
        print "Case #%d: %f" % (i+1, opt2(A, B, P));
