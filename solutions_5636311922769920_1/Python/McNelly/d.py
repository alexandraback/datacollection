def solve(k, c, s):
    res = []
    if s < (k + c - 1) / c:
        return 'IMPOSSIBLE'

    l = (k + c - 1) / c
    for i in xrange(l):
        items = map(
                lambda x: min(k, x + 1),
                range(i * c, i * c + c))
        x = 0
        for lv, num in enumerate(items):
            x += (k ** (c - lv - 1)) * (num - 1)
        res.append(x + 1)
    return ' '.join(map(str, res))


T = int(raw_input())

for case_ in xrange(T):
    (k, c, s) = map(int, raw_input().split())
    print "Case #%d:" % (case_ + 1),
    print solve(k, c, s)
