def calc(n,r):
    return n*((2*r-3)+2*(n+1))

T = int(raw_input())
for t in xrange(T):
    v = map(int,raw_input().split())
    l,r = 0,10**10
    while l<r:
        mid = (l+r+1)/2
        ink = calc(mid,v[0])
        if ink <= v[1]: l = mid
        else: r = mid-1
    print 'Case #%d: %d' %(t+1,l)
