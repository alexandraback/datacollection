#!/usr/bin/python

def get():
    n, m = map(int, raw_input().strip().split())
    grass = []
    for x in xrange(n):
        grass.append(map(int, raw_input().strip().split()))
    transpose = zip(*grass)

    def ok(s, v):
        return all(x <= v for x in s)

    for x in xrange(n):
        for y in xrange(m):
            v = grass[x][y]
            if not ok(grass[x], v) and not ok(transpose[y], v):
                return 'NO'
    return 'YES'

n = input()
for x in xrange(n):
    print 'Case #%d: %s' % (x+1, get())
