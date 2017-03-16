#/usr/bin/env python
# Google Code Jam Qualification Round 2016
# A. Counting Sheep
# https://code.google.com/codejam/contest/6254486/dashboard

def sleep(n):
    if n == 0:
        return 'INSOMNIA'
    i, s = 0, set([])
    while len(s) < 10:
        i += n
        s = s.union(str(i))
    return str(i)

with open('A-small-attempt0.in', 'r') as f:
    t = int(f.readline())
    with open('out.txt', 'w') as g:
        for i in xrange(t):
            n = int(f.readline())
            g.write('Case #%d: %s\n' % (i+1, sleep(n)))
