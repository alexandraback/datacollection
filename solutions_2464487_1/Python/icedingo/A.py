from decimal import *

cases = int(raw_input())

for case in xrange(cases):
    r, t = map(Decimal, raw_input().split())

    d_sq = Decimal((2*r-1)**2 + 8*t)
    d = d_sq.sqrt()

    rings = (1 - 2*r + d)/4
    
    print 'Case #%d: %d' % (case+1, rings)
