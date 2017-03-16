from sys import stdin

testcases = int(stdin.readline())


def calc_upper_limit(E, R, N, ub, lb, pos):
    i = pos - 1
    while 0 <= i:
        if lb[i] >= 0:
            t = (pos - i) * R
            return min(E, t)
        i = i - 1
    return E


def calc_lower_limit(E, R, N, ub, lb, pos):
    i = pos + 1
    while i < N:
        if ub[i] >= 0:
            t = ub[i] - R * (i - pos)
            return max(0, t)
        i = i + 1
    return 0


for testcase in xrange(1, testcases + 1):
    E, R, N = map(int, stdin.readline().split())
    v = map(int, stdin.readline().split())
    v = zip(v, xrange(0, N))
    v = sorted(v, reverse=True)

    ub = [-1] * N
    lb = [-1] * N
    result = 0

    for value, pos in v:
        # print 'value, pos: %d %d' % (value, pos)
        # print ub, lb
        up = calc_upper_limit(E, R, N, ub, lb, pos)
        low = calc_lower_limit(E, R, N, ub, lb, pos)
        # print up, low
        if up > low:
            result = result + value * (up - low)
            ub[pos] = up
            lb[pos] = low
        pass

    print 'Case #%d: %d' % (testcase, result)
