import sys
from math import *

T = int(sys.stdin.readline())
for test in range(T):
    r, t = sys.stdin.readline().split();
    r = long(r)
    t = long(t)
    low = 1L
    high = ceil(2e18)
    while(low < high):
        mid = low + (high - low + 1) / 2
        if (2 * mid * r + 2 * mid * mid - mid <=t):
            low = mid
        else:
            high = mid - 1
    print "Case #%d: %ld" % (test + 1, long(low))



