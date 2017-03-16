from sys import stdin

testcases = int(stdin.readline())


def check(R, T, k):
    need = ((2 * R + 1) + (2 * R + 4 * k - 3)) * k / 2
    return need <= T

for testcase in xrange(1, testcases + 1):
    R, T = map(long, stdin.readline().split())
    l, r = 1, T
    while l < r:
        mid = (l + r + 1) / 2
        if check(R, T, mid):
            l = mid
        else:
            r = mid - 1
    print 'Case #%d: %d' % (testcase, l)
