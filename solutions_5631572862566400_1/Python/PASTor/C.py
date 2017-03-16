#!/usr/local/bin/pypy

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math

if len(sys.argv) >= 2 and sys.argv[1] == 'debug':
    DEBUG = True
else:
    DEBUG = False


def check_cycle(m, mrev, origin):
    a = origin
    visited = [origin]
    while m[a] not in visited:
        a = m[a]
        visited.append(a)


    ind = visited.index(m[a])

    return len(visited) - ind


def longest(o, wo):
    a = o
    count = 1
    tovisit = mrev[a] - {wo}

    while len(tovisit) > 0:
        count += 1
        tovisit_new = set()
        for e in tovisit:
            tovisit_new.update(mrev[e])
        tovisit = tovisit_new

    return count



def check1_1():
    mx = 0
    for i in xrange(N):
        if m[m[i]] == i and i < m[i]:
            mx += longest(i, m[i]) + longest(m[i], i)

    return mx






_T = int(raw_input())
_tt = max(_T/10, 1)

for _cc in xrange(_T):
    print 'Case #{}:'.format(_cc+1),
    if _cc % _tt == 0:
        print >>sys.stderr, 'Solving: ', (_cc+1)*100/_T, '%'

    N = int(raw_input())
    m = map(int, raw_input().split())

    m = [m[i]-1 for i in xrange(N)]

    mrev = [set() for i in xrange(N)]
    for i in xrange(N):
        mrev[m[i]].add(i)

    # if DEBUG:
    #     print mrev

    res = 0

    for i in xrange(N):
        res = max( res, check_cycle(m, mrev, i))

    res = max( res, check1_1())

    print res


