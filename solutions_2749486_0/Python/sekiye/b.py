def solve():
    X, Y = map(int , raw_input().split())
    if X < 0:
        xbase = 'EW'
    else:
        xbase = 'WE'
    if Y < 0:
        ybase = 'NS'
    else:
        ybase = 'SN'
    return xbase * abs(X) + ybase * abs(Y)

T = int(raw_input())
for i in xrange(T):
    print "Case #%d:" % (i + 1), solve()
