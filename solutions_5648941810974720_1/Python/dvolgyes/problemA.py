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

range = xrange

sys.setrecursionlimit(5000)

digits = ["ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN", "EIGHT", "NINE"]

def solve(s):
    numbers = dict()
    numbers[0] = s.count("Z")
    numbers[2] = s.count("W")
    numbers[4] = s.count('U')
    numbers[6] = s.count('X')
    numbers[8] = s.count('G')

    numbers[1] = s.count('O') - numbers[2] - numbers[4] - numbers[0]
    numbers[7] = s.count('S') - numbers[6]
    numbers[5] = s.count('V') - numbers[7]
    numbers[9] = (s.count('N') - numbers[7] - numbers[1]) // 2
    numbers[3] = s.count('H') - numbers[8]
    result = ""
    for i in range(0,10):
        for j in range(0,numbers[i]):
            result += str(i)
    return result

T = int(sys.stdin.readline())

for t in range(1,T+1):
    s = sys.stdin.readline().strip()
    print("Case #%i: %s" % (t,solve(s)))
