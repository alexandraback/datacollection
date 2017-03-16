import math
cases = int(raw_input())
for c in xrange(cases):
    x = map(int, raw_input())
    y = map(int, raw_input().split())
    y = sorted(y, reverse=True)
    res = y[0]
    m = y[0]
    for r in range(1, m):
        move = 0
        for z in y:
            if z <= r:
                break
            move += math.ceil(float(z) / float(r)) - 1
        if move + r < res:
            res = move + r
    print('Case #%d: %d' % (c + 1, res))