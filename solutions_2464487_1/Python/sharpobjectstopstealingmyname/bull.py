T = int(raw_input())

for qq in xrange(1,T+1):
    r,t = map(int,raw_input().split(" "))
    c = 2**64
    ret = 0
    while c > 0:
        n = ret + c
        if n*2*r + n + (n*(n-1))*2 <= t:
            ret = n
        c /= 2
    print "Case #%d: %s"%(qq,ret)
