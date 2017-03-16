


def solve(r, t):
    left = 1
    right = t+1

    while (right-left > 1):
        mid = (left + right)/2
        if (mid*(2*r - 1) + 2*mid*mid <= t):
            left = mid
        else:
            right = mid

    return left

import sys
si = sys.stdin

T = int(si.readline())
for icase in range(T):
    r, t = map(int, si.readline().split())
    n = solve(r, t)
    print "Case #%d:" % (icase+1), n
