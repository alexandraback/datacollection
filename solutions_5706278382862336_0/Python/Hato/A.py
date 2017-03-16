#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import fractions
import math

def solve(P, Q):
    IMP = "impossible"
    
    gcd = fractions.gcd(P, Q)
    if gcd > 1:
        P /= gcd
        Q /= gcd
    e = math.log2(Q)
    if e != int(e):
        return IMP
    
    for gen in range(1, int(e) + 1):
        P *= 2
        if P / Q >= 1:
            return gen

    # ???    
    return IMP


# main
me = sys.argv[0].split("/")[-1].replace(".py", "")
#file = me + "-sample"
file = me + "-small-attempt0"
#file = me + "-large"

with open(file + ".in", "r") as fdin:
    with open(file + ".out", "w") as fdout:

        T = int(fdin.readline())
        for ncase in range(T):
            P, Q = [int(x) for x in fdin.readline().split("/")]

            result = solve(P, Q)
    
            line = "Case #%d: %s" % (ncase + 1, result)
            print(line) 
            fdout.write("%s\n" % line)
    