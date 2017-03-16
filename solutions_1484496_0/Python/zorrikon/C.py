#!/usr/bin/python
#C.py
#Author: James Damore
#Created on: May 05, 2012
#Time-stamp: <2012-05-05 12:57:31>
#cat Downloads/C-small-attempt0.in | ~/C.py > output.txt

import math, sys, itertools
import numpy as np

def dbgln(a): sys.stderr.write(str(a) + "\n")
def read_ints(lines=None, fmt=int):
    if lines is None: return map(int, raw_input().split())
    return [map(fmt, raw_input().split()) for _ in range(lines)]


def read_input():
    s = read_ints()
    N, S = s[0], s[1:]
    d = {}
    for i in range(1 << N):
        s = sum(S[j] for j in range(N) if (1 << j) & i)
        if s in d:
            i -= (i & d[s])
            d[s] -= (i & d[s])
            s1 = [S[j] for j in range(N) if (1 << j) & i]
            s2 = [S[j] for j in range(N) if (1 << j) & d[s]]
            return '\n' + ' '.join(map(str, s1)) + '\n' + \
                          ' '.join(map(str, s2))
        d[s] = i
    return 'Impossible'


numCases=input()
for i in range(1, numCases+1):
    #read_input()
    #dbgln(i)
    output = read_input()
    print "Case #%d:" % i, output
