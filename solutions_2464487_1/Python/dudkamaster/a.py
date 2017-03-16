T = input()

for test in xrange(1, T+1):
    r,t = map(int,raw_input().split())
    lf = 1
    rg = 200000000000000000000
    while lf+1<rg:
        x = (lf+rg)/2
        v = (2*r+1 + 2*(x-1))*x
        if v > t:
            rg = x
        else:
            lf = x
    ans = rg
    v = (2*r+1 + 2*(rg-1))*rg
    if v > t:
        ans = lf
    print 'Case #%d: %d' % (test, ans)
