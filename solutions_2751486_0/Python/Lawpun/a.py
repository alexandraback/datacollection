#!python
from __future__ import print_function
from heapq import *
from collections import *
from itertools import *
import sys, random

sys.setrecursionlimit(10000)

def gets():
    try:
        return raw_input()
    except EOFError:
        return None

def getint():
    return int(gets())

def getints():
    return [int(x) for x in gets().split()]

def f(s, n):
    for i in xrange(len(s)):
        if i+n <= len(s) and all(c not in ('a','e','i','o','u') for c in s[i:i+n]):
            return True
    return False

def solve(s, n):
    ans = 0
    for i in xrange(len(s)):
        for j in xrange(i+n, len(s)+1):
            #print(s[i:j])
            if f(s[i:j],n):
                ans += 1
    return ans


T = getint()
for ic in xrange(T):
    s,n = gets().split()
    ans = solve(s, int(n))
    print("Case #{0}: {1}".format(ic+1, ans))
