from sys import *
from math import *

values = []
for i in xrange(1, 10000001):
    if str(i) == str(i)[::-1] and str(i**2) == str(i**2)[::-1]:
        values.append(i**2)
values.append(99999999999999999999999999999999)

t = int(raw_input())
for c in xrange(t):
    a, b = map(int, raw_input().split())
    aS = -1
    bS = -1
    for key, value in enumerate(values):
        if aS == -1 and value >= a:
            aS = key
        if bS == -1 and value > b:
            bS = key
            break
    print "Case #{0}: {1}".format(c + 1, bS - aS)

