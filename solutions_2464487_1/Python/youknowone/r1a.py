
from bigfloat import *
import math

def plain(r, n):
    return 2 * r + 4 * n - 3

def sum(r, n):
    s = 0
    for i in xrange(1, n + 1):
        s += plain(r, i)
    return s

def getn(r, t):
    with precision(1000):
        x = 8 * t + 4 * r ** 2 -  4 * r + 1
        rt = sqrt(x)
        v = rt - (2 * r - 1)
        v = v / 4
    return int(v)

if __name__ == '__main__':
    case_count = input()
    for x in xrange(0, case_count):
        r, t = map(long, raw_input().split(' '))
        n = getn(r, t)
        print 'Case #%d:' % (x + 1), n
