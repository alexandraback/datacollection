#/usr/bin/env python
# Google Code Jam Qualification Round 2016
# B. Revenge of the Pancakes
# https://code.google.com/codejam/contest/6254486/dashboard#s=p1

def happy(stack):
    s = stack + '+'
    t = s[0]
    c = 0
    for p in s[1:]:
        if p != t:
            c += 1
            t = p
    return c

with open('B-large.in', 'r') as f:
    t = int(f.readline())
    with open('test.out', 'w') as g:
        for i in xrange(t):
            stack = f.readline().strip()
            g.write('Case #%d: %d\n' % (i+1, happy(stack)))
