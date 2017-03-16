#/usr/bin/env python
# Google Code Jam Qualification Round 2016
# D. Fractiles
# https://code.google.com/codejam/contest/6254486/dashboard#s=p3

def test(k, c, s):

    x = -1 * ((-1 * k) // c)
    if x > s:
        return 'IMPOSSIBLE'

    t = []

    for i in xrange(x):
        n = range(i * c, min((i + 1) * c, k))
        s = 0
        for j in xrange(len(n)):
            s += n[j] * (k ** (len(n) - j - 1))
        t.append(s)

    t = [str(x+1) for x in set(t)]

    return ' '.join(t)

with open('D-large.in', 'r') as f:
    t = int(f.readline())
    with open('test.out', 'w') as g:
        for i in xrange(t):
            (k, c, s) = [int(x) for x in f.readline().split()]
            out = test(k, c, s)
            g.write('Case #%d: %s\n' % (i+1, out))
