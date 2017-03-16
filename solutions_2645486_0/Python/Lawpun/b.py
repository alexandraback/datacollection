#!python
from __future__ import print_function
from heapq import *
from collections import *
from itertools import *
import sys

with open(sys.argv[-1], 'r') as fs:
    stdin_lines = deque(fs.readlines())

def gets():
    if len(stdin_lines) > 0:
        return stdin_lines.popleft().rstrip('\r\n')
    return None

def getint():
    return int(gets())

def getints():
    return [int(x) for x in gets().split()]

def subsets(x):
    for i in range(2**len(x)):
        s = []
        for j in range(len(x)):
            if 1 << j & i != 0:
                s.append(x[j])
        yield tuple(s)

def dp(i, en_left, E, R, N, V, cache):
    if i == N-1:
        return en_left * V[i]

    key = (i, en_left)
    if key not in cache:
        ans = 0
        for e in range(0, en_left+1):
            new_ans = e*V[i] + dp(i+1, min(E,en_left-e+R), E, R, N, V, cache)
            if new_ans > ans:
                ans = new_ans
        cache[key] = ans
    return cache[key]

def solve(E, R, N, V):
    #print(V)
    return dp(0, E, E, R, N, V, {})

T = getint()
for ic in range(T):
    E, R, N = getints()
    V = getints()
    ans = solve(E, R, N, V)
    print("Case #{0}: {1}".format(ic+1, ans))
