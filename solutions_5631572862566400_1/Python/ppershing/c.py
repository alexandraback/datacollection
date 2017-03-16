import sys
import numpy as np
import collections

def fix_circle(buddy, circle, start):
    used = {}
    x = start
    while not x in used:
        used[x] = True
        x = buddy[x]
    c = [x]
    y = buddy[x]
    while y != x:
        c.append(y)
        y = buddy[y]
    c = normalize_circle(c)
    #print c, len(used) - len(c)
    circle[start] = c, len(used) - len(c), x

def normalize_circle(c):
    x = np.argmin(c)
    return tuple(c[x:] + c[:x])

def solve(testcase):
    n = int(sys.stdin.readline().strip())
    buddy = map(int, sys.stdin.readline().strip().split())
    buddy = [x-1 for x in buddy]
    circle = [None for i in range(n)]
    for i in range(n):
        fix_circle(buddy, circle, i)

    #print circle
    maxc = max(len(c) for c,l,x in circle)
    tmp = collections.defaultdict(int)
    for c,l,x in circle:
        if len(c) > 2:
            continue
        tmp[c] = max(tmp[c], l + len(c))
    
    tmp2 = collections.defaultdict(lambda : collections.defaultdict(int))
    for c,l,x in circle:
        tmp2[c][x] = max(tmp2[c][x], l)

    #print tmp2
    chains = []
    for xx in tmp2:
        if len(xx) > 2:
            continue
        yy = sorted(y for y in tmp2[xx].values())
        chains.append(sum(yy[:2]) + len(xx))

    res = max(maxc, sum(chains))
    print "Case #%d: %d" % (testcase, res)

for t in range(int(sys.stdin.readline().strip())):
    solve(t+1)
