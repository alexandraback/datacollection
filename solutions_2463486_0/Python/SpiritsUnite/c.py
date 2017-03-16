from sys import *
from math import *

t = int(raw_input())
for c in xrange(t):
    count = 0
    a, b = map(int, raw_input().split())
    a = int(ceil(a**.5))
    b = int(floor(b**.5))
    for i in xrange(a, b + 1):
        if str(i) == str(i)[::-1] and str(i**2) == str(i**2)[::-1]:
            count += 1
    print "Case #{0}: {1}".format(c + 1, count)

