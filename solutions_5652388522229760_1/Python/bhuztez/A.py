#!/usr/bin/env python2

def solve(N):
    if N == 0:
        return 'INSOMNIA'

    a = 0
    s = set()

    while len(s) < 10:
        a += N
        s.update(map(int,str(a)))
    return a

T = int(raw_input())

for i in xrange(T):
    print 'Case #%d:' % (i+1),
    print solve(int(raw_input()))
