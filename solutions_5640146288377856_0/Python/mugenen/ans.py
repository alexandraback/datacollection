import sys

T = input()

for t in xrange(T):
    R, C, W = map(int, raw_input().split())
    
    d = C / W
    
    result = 0
    result += d * (R - 1)
    
    r1 = 0
    r1 += d
    if C % W > 0:
        r1 += W
    else:
        r1 += W - 1
    
    r2 = 0
    r2 += (d - 1)
    r2 += W
    
#    print result, r1, r2
    result += max(r1, r2)
    
    print 'CASE #{}: {}'.format(t + 1, result)
