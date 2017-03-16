#!/usr/bin/python

def checkRow(r):
    if r.count('X') == 4 or r.count('X') == 3 and 'T' in r:
        return 'X won'
    if r.count('O') == 4 or r.count('O') == 3 and 'T' in r:
        return 'O won'

def solve():
    rows = [raw_input() for i in xrange(4)]
    raw_input()
    full = True
    for r in rows:
        if '.' in r: full = False
        e = checkRow(r)
        if e is not None: return e
    cols = zip(*rows)
    for c in cols:
        e = checkRow(c)
        if e is not None: return e
    d1 = []; d2 = []
    for i in xrange(4):
        d1.append(rows[i][i])
        d2.append(rows[3-i][i])
    e = checkRow(d1)
    if e is not None: return e
    e = checkRow(d2)
    if e is not None: return e
    if full:
        return 'Draw'
    else:
        return 'Game has not completed'

T = input()
for i in xrange(T):
    print 'Case #%s: %s' % (i+1, solve())
