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

def solve(A, N, s):
    size = A
    ans = 0
    while len(s) > 0:
        if size > s[0]:
            size += s.popleft()
        else:
            break

    if len(s) > 0:
        if size == 1:
            ans += len(s)
        else:
            ans = len(s)
            for cut in xrange(len(s)+1):
                inserted = 0
                newsize = size
                i = 0
                while i + cut < len(s):
                    while newsize <= s[i]:
                        newsize += newsize - 1
                        inserted += 1
                    newsize += s[i]
                    i += 1
                ans = min(ans, cut + inserted)

    return ans
"""
            inserted = 0
            newsize = size
            j = 0
            while j < len(s):
                while newsize <= s[j]:
                    newsize += newsize - 1
                    inserted += 1
                newsize += s[j]
                j += 1
            if inserted >= len(s):
                ans += len(s)
                break
            else:
                inserted = 0
                newsize = size
                while newsize <= s[0]:
                    newsize += newsize - 1
                    inserted += 1
                ans += inserted
                size = newsize
"""

T = getint()
for ic in xrange(T):
    A, N = getints()
    s = deque(sorted(getints()))
    ans = solve(A, N, s)
    print("Case #{0}: {1}".format(ic+1, ans))
