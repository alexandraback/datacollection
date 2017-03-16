def solve(R, C, W):

    trace = C / W
    right = C % W

    till_end = trace + right + max(0, W - right)
    if right == 0:
        not_till_end = trace - 1 + W

        return min(till_end, not_till_end)

    return till_end

    # t = trace - 1
    # right = C - t * W
    # near_end_s = t + right + max(0, W - right)

    # return min(end_s, near_end_s)

T = int(raw_input())

for i in xrange(T):
    R, C, W = [int(x) for x in raw_input().split()]

    print 'Case #%d: %d' % (i + 1, solve(R, C, W))
