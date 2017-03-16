#!/usr/bin/python

F_IN = 'input'
            
def dumb(v, e, r, start):
    if len(v) == 0:
        return 0
    i = r
    largest = 0
    while i <= start:
        # spend i on first
        largest = max(largest, i * v[0] + dumb(v[1:], e, r, start - i + r))
        i += 1
    return largest

with open(F_IN, 'r') as f:
    nlines = int(f.readline())
    i = 0
    while i < nlines:
        i += 1
        ern = f.readline()
        ern = ern.split(' ')
        e = int(ern[0])
        r = int(ern[1])
        n = int(ern[2])
        v = f.readline()
        v = v.split(' ')
        v = [int(x) for x in v]
        print 'Case #{}: {}'.format(i, dumb(v, e, r, e))
