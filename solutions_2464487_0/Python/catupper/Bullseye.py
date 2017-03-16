def calc(r, x):
    res = (x + 1) * (2*r+1)
    res += 2*x*(x+1)
    return res

for x in xrange(1, input() + 1):
    r,t=map(int,raw_input().split())
    bottom = 0
    top = 1 << 60
    while(top - bottom > 1):
        mid = (top + bottom ) / 2
        if(calc(r, mid) <= t):
            bottom = mid
        else:
            top = mid
    print "Case #%d: %d"%(x, bottom + 1)
    
