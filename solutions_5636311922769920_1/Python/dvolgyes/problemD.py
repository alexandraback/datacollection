#!/usr/bin/python
from __future__ import division,print_function
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org
import itertools
import operator
import string

sys.setrecursionlimit(5000)

T = int(sys.stdin.readline())

def parse(s,base):
    result = 0
    for idx in range(len(s)):
        result += (int(s[-idx-1]))*(base**idx)
    return result

def convert(a,b,K,C):
    position = 0
    cnt = 0
    for i in reversed(range(a,b)):
        cnt = 0
        position += i*K**cnt
        cnt+=1
    return position+1


def solve(K,C,S):
    nr = (K // C)
    remaining = K % C
    if S<nr: return "IMPOSSIBLE"
    if S==nr and remaining > 0: return "IMPOSSIBLE"

    solution = ""

    i=0
    while i<nr:
        solution += " "+str(convert(i*C,(i+1)*C,K,C))
        i+=1
    if remaining > 0:
        solution += " "+str(convert(i*C,K,K,C))

    return solution.strip()

for t in range(1,T+1):
    K,C,S = map(int,sys.stdin.readline().strip().split())
    print("Case #%i: %s" % (t,solve(K,C,S)))

