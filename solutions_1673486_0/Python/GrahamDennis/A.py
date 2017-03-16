#!/usr/bin/env python
# encoding: utf-8
"""
A.py
"""

import sys

def main():
    f = open(sys.argv[1])
    T = int(f.readline())
    
    for t in xrange(T):
        A, B = map(int, f.readline().split())
        B += 1 # Enter
        p = map(float, f.readline().split())
        P = []
        P_i = 1.0
        for p_i in p:
            P_i *= p_i
            P.append(P_i)
        
        minCost = 1 + B
        for i, P_i in enumerate(P):
            minCost = min(minCost, 2*(A-(i+1)) + B-A + (1.0-P_i)*B)
        
        print "Case #%i: %f" % (t+1, minCost)

if __name__ == "__main__":
    sys.exit(main())
