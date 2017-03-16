#!/usr/local/bin/pypy

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math

if len(sys.argv) >= 2 and sys.argv[1] == 'debug':
    DEBUG = True
else:
    DEBUG = False


def solve(i, s, e):
    if DEBUG: print >> sys.stderr, 'i, s, e', i, s, e
    if i == len(a):
        return 0

    if s[a[i][0]] == 1 or e[a[i][1]] == 1:
        return solve(i+1, s, e)
    else:
        if DEBUG: print >> sys.stderr, 'NOT i, s, e', i, s, e

        tmp = solve(i+1, s, e)

        s[a[i][0]] -= 1
        e[a[i][1]] -= 1

        if DEBUG: print >> sys.stderr, 'FAKE i, s, e', i, s, e

        tmp2 = 1 + solve(i+1, s, e)
        s[a[i][0]] += 1
        e[a[i][1]] += 1

        return max(tmp, tmp2)


_T = int(raw_input())
_tt = max(_T/10, 1)

for _cc in xrange(_T):
    print 'Case #{}:'.format(_cc+1),
    if _cc % _tt == 0:
        print >>sys.stderr, 'Solving: ', (_cc+1)*100/_T, '%'

    N = int(raw_input())

    a = []
    start = coll.defaultdict(int)
    end = coll.defaultdict(int)
    for i in xrange(N):
        s,e = raw_input().split()
        a.append((s,e))

        start[s] += 1
        end[e] += 1


    print solve(0, start, end)


