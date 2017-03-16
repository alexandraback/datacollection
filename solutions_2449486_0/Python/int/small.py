#!/usr/bin/python

def get():
    n, m = map(int, raw_input().strip().split())
    grass = []
    for x in xrange(n):
        grass.append(map(int, raw_input().strip().split()))
    transpose = zip(*grass)

    def ok(s):
        return all(x == 1 for x in s)

    for x in xrange(n):
        for y in xrange(m):
            if grass[x][y] == 1:
                if not ok(grass[x]) and not ok(transpose[y]):
                    return 'NO'
    return 'YES'

n = input()
for x in xrange(n):
    print 'Case #%d: %s' % (x+1, get())
