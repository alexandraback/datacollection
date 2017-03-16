#!/usr/bin/python
import math
import sys
import IPython

test = 0


def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

def f(r, t):
    return int(math.floor((-(2*r-1) + isqrt((2*r-1)**2 + 8*t))/4))



lines = open(sys.argv[1]).read().split('\n')

test_num=int(lines[0])
idx=1
for x in xrange(test_num):
    curr_line = lines[idx]
    idx += 1

    r, t = map(int, curr_line.split(' '))

    ans = f(r,t)
    print 'Case #%s: %s' % (x+1, ans)

if test:
    print 'f(1,9): %s' % f(1,9)
    print 'f(1,10): %s' % f(1,10)
    print 'f(3,40): %s' % f(3,40)
    print 'f(1,1000000000000000000): %s' % f(1,1000000000000000000)
    print 'f(10000000000000000,1000000000000000000): %s' % f(10000000000000000,1000000000000000000)

