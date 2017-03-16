def func(rings,r):
    n=rings*2-1
    return 2*rings*r + n*(n+1)/2

def puol(r,t):
    low=1
    high=100000000000000000000000000000000
    while(high-low > 1):
        mid=(high+low)/2
        if(func(mid,r) <= t):
            low=mid
        else:
            high=mid
    if(func(high,r) <= t):
        return high
    if(func(high-1,r) <=t):
        return high-1

T = int(raw_input())
for test in range(T):
    u = raw_input().split()
    print "Case #%d: %d" % (test+1,puol(int(u[0]),int(u[1])))


