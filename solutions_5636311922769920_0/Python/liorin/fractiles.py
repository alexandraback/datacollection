# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys

# <codecell>

num_cases = sys.stdin.readline()

"""this works only for k == s """

def solve(k,c,s):
    if (s == k):
        return range(1,s+1)
    l = []
    return l


for num, line in enumerate(sys.stdin):
    k, c, s = [int(x) for x in line.split()]
    l = solve(k,c,s)
    out = "Case #{0}:".format(num+1)
    for x in l:
        out += " {0}".format(x) 
    if not l:
        out += " IMPOSSIBLE"
    print out

# <codecell>


