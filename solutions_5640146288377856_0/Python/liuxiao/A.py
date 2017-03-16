def solve(c, w):
    if c >= 2 * w:
        return solve(c - w, w) + 1
    if c == w:
        return c
    return w + 1
T = input()
for t in range(1, T + 1):
    r, c, w = map(int, raw_input().split())
    # result = r * (int(c / w) + (w - 1) + (c % w))
    # result = r * (int(c / w) + (w - 1) + (c % w))
    result = r * solve(c, w)
    # result = r * ((c - w) / w + (c - w) % w + w)
    print 'Case #%d: %d' % (t, result)
