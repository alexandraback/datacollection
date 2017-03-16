import sys


def solve(r, t):
    def area(x):
        return 2 * r * x + x * (2 * x - 1)
    right, left = t, 0 
    while left + 2 < right:
        mid = (left + right) / 2
        if area(mid) <= t:
            left = mid
        else:
            right = mid
    x = max(left - 2, 1)
    while area(x) <= t:
        x += 1
    return x - 1

T = int(sys.stdin.readline())
for caset in xrange(T):
    r, t = map(int, sys.stdin.readline().split())
    print 'Case #%d: %d' % (caset + 1, solve(r, t))
