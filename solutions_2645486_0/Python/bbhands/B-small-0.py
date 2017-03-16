#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math
from decimal import *

if __name__ == "__main__":

    fin = open("B-small-0.in", "r")
    fout = open("B-small-0.out", "w")
    T = int(fin.readline())
    #T = int(sys.stdin.readline())
    for k in xrange(0, T):
        #E, R, N = map(int, sys.stdin.readline().split(' '))
        E, R, N = map(int, fin.readline().split(' '))
        #V = map(int, sys.stdin.readline().split(' '))
        V = map(int, fin.readline().split(' '))
        if R>=E:
            answer = E*(sum(V))
        else:
            answer = E*max(V)+R*(sum(V)-max(V))

        #print("Case #%i: %i\n" % (k+1, answer))
        fout.write("Case #%i: %i\n" % (k+1, answer))
    fin.close()
    fout.close()

