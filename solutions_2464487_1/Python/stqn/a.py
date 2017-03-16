T = input()
for _ in xrange(T):
    [r, t] = map(int, raw_input().split())
    (L, R) = (1, int((t / 2) ** 0.5) + 1)
    while L + 1 < R:
        m = (L + R) / 2
        if 2 * m * m + (2 * r - 1) * m <= t:
            L = m
        else:
            R = m
    print "Case #%d: %d" % (_ + 1, L)
