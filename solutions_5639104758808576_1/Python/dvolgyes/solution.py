#!/usr/bin/python
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org


def toint(string):
    result = []
    for c in string:
        result.append(int(c))
    return result

N = int(sys.stdin.readline())

solutions = []

for case in range(0, N):
    solution = ""
    Smax, S = sys.stdin.readline().strip().split()
    Smax = int(Smax)
    assert(Smax + 1 == len(S))
    S = toint(S)

    friends = 0
    standing = 0
    for i in range(0, Smax + 1):
        friends += max(0, i - standing - friends)
        standing += S[i]
    solutions.append(friends)

for case in range(0, N):
    print "Case #%i: %s" % (case + 1, solutions[case])
