#!/usr/bin/env python

def check(p, s):
    return all(c == p or c == 'T' for c in s)

def calc(a):
    for p in ('X', 'O'):
        if check(p, (a[i][i] for i in xrange(4))) or check(p, (a[i][4 - i - 1] for i in xrange(4))):
            return '%s won' % p
        for i in xrange(4):
            if check(p, a[i]) or check(p, (a[j][i] for j in xrange(4))):
                return '%s won' % p
    if '.' in ''.join(a):
        return 'Game has not completed'
    return 'Draw'

T = input()
for i in xrange(T):
    a = [raw_input().strip() for j in xrange(4)]
    raw_input()
    print 'Case #%d: %s' % (i + 1, calc(a))
