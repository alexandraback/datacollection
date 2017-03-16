import sys
import math

def good(x, r, t):
    return (2*r+1)*x + 2*(x*(x-1)) <= t

tc = (int)(sys.stdin.readline())
for tt in xrange(tc):
    r, t = sys.stdin.readline().split()
    r = (int)(r)
    t = (int)(t)

    low = 1
    high = t
    best = 1
    while(low<=high):
        mid = (low+high)/2
        if(good(mid, r, t)):
            best = mid
            low = mid+1
        else:
            high = mid-1
    
    print "Case #%d: %d" % (tt+1, best)
