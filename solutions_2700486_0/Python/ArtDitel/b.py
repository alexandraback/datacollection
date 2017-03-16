from sys import stdin


def sq(h):
    s = (h-1)*2 + 1
    return s * (s + 1) / 2


def dp(n,a,b,d):
    if a == 0 and b == 0:
        return 1.0
    if (a,b) in d:
        return d[(a,b)]
    def dp2():
        if a == 0:
            return dp(n,0,b-1,d) * 0.5
        if b == 0:
            return dp(n,a-1,0,d) * 0.5
        if a == n and b == n:
            return 1.0
        if a == n:
            return dp(n,a,b-1,d) + 0.5*dp(n,a-1,b,d)
        if b == n:
            return dp(n,a-1,b,d) + 0.5*dp(n,a,b-1,d)
        return 0.5 * (dp(n,a-1,b,d) + dp(n,a,b-1,d))
    d[(a,b)] = dp2()
    #print "dp",a,b,d[(a,b)]
    return d[(a,b)]


def solve2(n, k, t):
    #print "solve",n,k,t
    res = 0.0
    d = { }
    for i in xrange(n+1):
        for j in xrange(n+1):
            if i + j == k and i >= t:
                #print "go",i,j,dp(n,i,j,d)
                res += dp(n,i,j,d)
    return res


def solve(n,x,y):
    h = 0
    while n >= sq(h+1):
        h += 1
    reqh = (abs(x) + y) / 2 + 1
    if reqh <= h:
        return 1.0
    s = (h)*2 + 1
    if reqh > h + 1:
        return 0.0
    reqw = s - abs(x)
    nlast = n - sq(h)
    return solve2(s-1, nlast, reqw)


def rl():
    return [int(x) for x in stdin.readline().strip().split()]


t, = rl()
for tc in xrange(1, t + 1):
    print "Case #{0}: {1:.7f}".format(tc, solve(*rl()))
