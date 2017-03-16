#/usr/bin/env python
# Google Code Jam Qualification Round 2016
# C. Coin Jam
# https://code.google.com/codejam/contest/6254486/dashboard#s=p2

n, j = 16, 50
s = []
k = 0

def factor(x):
    for i in xrange(2, int(x**0.5) + 1):
        if x % i == 0:
            return i
    return 0

with open('test.out', 'w') as g:
    g.write('Case #1:')
    for i in xrange(2**(n-2)):
        c = bin(i)[2:]
        c = '1' + '0'*(n-2-len(c)) + c + '1'
        f = []
        for b in xrange(2, 11):
            f.append(factor(int(c,b)))
        f = [str(x) for x in f if x > 0]
        if len(f) == 9:
            k += 1
            g.write('%s %s\n' % (c, ' '.join(f)))
        if k == j:
            break
