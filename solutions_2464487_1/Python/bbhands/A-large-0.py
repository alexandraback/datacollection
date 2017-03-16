#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math

if __name__ == "__main__":

    fin = open("A-large-0.in", "r")
    fout = open("A-large-0.out", "w")
    T = int(fin.readline())

    for k in xrange(0, T):
        r, t = map(int, fin.readline().split())
        answer = ((1-2*r)+math.sqrt(4*(r**2)-4*r+1+8*t))//4
        
        fout.write("Case #%i: %i\n" % (k+1, answer))
    
    fin.close()
    fout.close()

