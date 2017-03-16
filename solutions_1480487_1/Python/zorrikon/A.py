#!/usr/bin/python
#A.py
#Author: James Damore
#Created on: May 05, 2012
#Time-stamp: <2012-05-05 12:38:29>
#cat Downloads/A-small-attempt0.in | ~/A.py > output.txt

import math, sys
import numpy as np

def dbgln(a): sys.stderr.write(str(a) + "\n")
def read_ints(lines=None, fmt=int):
    if lines is None: return map(int, raw_input().split())
    return [map(fmt, raw_input().split()) for _ in range(lines)]


def read_input():
    x = read_ints()
    N, s = x[0], x[1:]
    X = float(sum(s))
    S = sorted(zip(s, range(N)))
    res = [0] * N
    sums = [sum(ss for ss, _ in S[:i]) for i in range(1, N + 1)]
    for i in range(N):
        for j in range(i, N):
            Y = 1 / X * ((sums[j] + X) / (j + 1) -  S[i][0])
            if j < N - 1 and S[i][0] + Y * X > S[j + 1][0]:
                continue              
            res[S[i][1]] = Y * 100 if Y >= 0 else 0
            break
    return ' '.join(map(str, res))


numCases=input()
for i in range(1, numCases+1):
    #read_input()
    #dbgln(i)
    output = read_input()
    print "Case #%d:" % i, output
