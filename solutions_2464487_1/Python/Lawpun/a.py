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
    return [long(x) for x in gets().split()]

def solve(r, t):
    left = 0
    right = 10**18

    ans = 0
    last_round = False
    while right - left > 0 and not last_round:
        if right - left == 1:
            last_round = True
        mid = (left + right) / 2
        #print("Try {0}".format(mid))
        cost = 2*r*mid + mid + 2 * (mid-1) * mid
        if t >= cost:
            ans = max(ans, mid)
            left = mid
            #print("Yes")
        else:
            right = mid
            #print("No")
    return ans


T = getint()
for ic in range(T):
    r, t = getints()
    ans = solve(r, t)
    print("Case #{0}: {1}".format(ic+1, ans))
