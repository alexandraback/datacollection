#!/usr/bin/python
# -*- coding: utf-8 -*-

from fractions import Fraction
from math import log

def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)

if __name__ == "__main__":

    fin = open("A-small-0.in", "r")
    fout = open("A-small-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        P, Q = tuple(map(int, fin.readline().strip().split('/')))
        vida = Fraction(P, Q)
            
        if not is_power2(vida.denominator):
            answer = "impossible"
        else:
            answer = 0
            while vida<1:
                vida *= 2
                answer += 1

            if answer >40:
                answer = "impossible"

        fout.write("Case #%i: %s\n" % (t+1, answer))
    
    fin.close()
    fout.close()

