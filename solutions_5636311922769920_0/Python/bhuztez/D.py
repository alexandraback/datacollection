#!/usr/bin/env python2

def base_k(K, l):
    r = 0
    for i in xrange(len(l)):
        r = r * K + l[i]
    return r

def tiles(K, C):
    for s in xrange(0,K,C):
        yield base_k(K,range(s,min(K,s+C),1)) + 1

def solve():
    K, C, S = map(int,raw_input().split())
    t = list(tiles(K, min(K,C)))
    if len(t) > S:
        print 'IMPOSSIBLE'
    else:
        print ' '.join(map(str,t))

# index from 0
# turn into a K-base number
# having digits, a b c, then a|b|c is covered

# now seeking solution of non-completes
# we just compose those numbers

#  XX
#  XX XX
#  XX XX XX XX


T = int(raw_input())
for i in xrange(T):
    print 'Case #%d:' % (i+1),
    solve()
