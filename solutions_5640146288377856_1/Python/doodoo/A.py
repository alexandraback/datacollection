def solve(R, C, W):

    trace = C / W
    right = C % W

    till_end = trace + right + max(0, W - right)
    if right == 0:
        not_till_end = trace - 1 + W

        last_line = min(till_end, not_till_end)
    else:
        last_line = till_end

    return (R - 1) * trace + last_line

T = int(raw_input())

for i in xrange(T):
    R, C, W = [int(x) for x in raw_input().split()]

    print 'Case #%d: %d' % (i + 1, solve(R, C, W))
