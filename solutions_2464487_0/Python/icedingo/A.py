import math
cases = int(raw_input())

for case in xrange(cases):
    r, t = map(int, raw_input().split())

    rings = (1 - 2*r + math.sqrt((2*r-1)**2 + 8*t))/4
    
    print 'Case #%d: %d' % (case+1, rings)
