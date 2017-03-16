import math
def solve(B, C):
    #4*x+B <= floor(math.sqrt(float(B**2)-8*C))
    l, h = 0, 5*10**9
    while h - l > 1:
        m = (h+l)/2
        if (4*m+B)**2 <= B**2-8*C:
            l = m
        else:
            h = m
    return l

nCase = int(raw_input())
for _ in range(1, nCase+1):
    r, t = map(long, raw_input().split())
    print 'Case #%d: %d' % (_, solve(2*r-1, -t))
