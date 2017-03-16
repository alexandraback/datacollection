#!/usr/bin/env python
T = input()
def f(n):
    if n == 0: return 'INSOMNIA'
    s = set()
    i = 1
    while len(s) != 10:
        s |= set(str(n*i))
        i += 1
    return n*(i-1)

for i in xrange(1,T+1):
    x = input()
    print 'Case #{}:'.format(i), f(x)

