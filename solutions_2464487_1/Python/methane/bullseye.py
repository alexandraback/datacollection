def solve(r, t):
    def use(n):
        return 2*n*r + n*(2*(n-1) + 1)

    min_, max_ = 1, t
    while min_ < max_:
        mid = (min_ + max_) // 2
        if use(mid) > t:
            max_ = mid
        else:
            if min_ == mid:
                break
            min_ = mid
    return min_


import sys
T = int(sys.stdin.readline())
for i in range(1, T+1):
    r, t = map(int, sys.stdin.readline().split())
    print "Case #%d: %d" % (i, solve(r, t))
