#!/usr/bin/python

from sys import stdin

def f(p, i, q):
    q.add(i)
    s = []
    s.extend(p[i])
    while s:
        i = s.pop()
        if i in q:
            return 1
        q.add(i)
        s.extend(p[i])
    return 0

T = int(stdin.readline())
for x in range(1, T + 1):
    N = int(stdin.readline())
    p = {}
    for i in range(1, N + 1):
        p[i] = map(int, stdin.readline().split())[1:]
    y = 'No'
    for i in range(1, N + 1):
        if f(p, i, set()):
            y = 'Yes'
            break
    print 'Case #%d: %s' % (x, y)

