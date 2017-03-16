#/usr/bin/env python
# Google Code Jam Qualification Round 2016
# D. Fractiles
# https://code.google.com/codejam/contest/6254486/dashboard#s=p3

with open('D-small-attempt1.in', 'r') as f:
    t = int(f.readline())
    with open('test.out', 'w') as g:
        for i in xrange(t):
            (k, c, s) = [int(x) for x in f.readline().split()]
            out = ' '.join([str(x) for x in xrange(1, k+1)])
            g.write('Case #%d: %s\n' % (i+1, out))
