__author__ = 'dkopiychenko'

import math

def test(k,c,s,l):
    g = set([])
    pp = [k**i for i in xrange(c-1,-1,-1)]
    for x in l:
        y = x-1
        for z in pp:
            g.add(y / z)
            y = y % z
    if len(g) == k: return True
    return False


def solve(k,c,s):
    r = -(-k//c)
    if s < r: return 'IMPOSSIBLE'
    l = []
    n = 0
    g = 0
    for i in xrange(k):
        n += i*k**(c-g-1)
        g += 1
        if g == c:
            g = 0
            l.append(n+1)
            n = 0
    if g > 0: l.append(n+1)
    if not test(k,c,s,l): print 'AAAAAA'
    return ' '.join(map(str,l))

t = int(raw_input())
for i in xrange(t):
    k,c,s = map(int,raw_input().split())
    print 'Case #' + str(i+1) + ': ' + solve(k,c,s)

