#!/usr/bin/env python


def get_input(func):
    raw = raw_input().split(' ')
    return map(func, raw)


def compute(i):
    typed = get_input(int)
    n = typed[0]
    point = typed[1:]
    total = sum(point)
    result = []
    k = n
    t2 = total * 2
    for x in point:
        if (total * 2 - x - (n - 1) * x) < 0:
            t2 -= x
            k -= 1
    for x in point:
        y = (t2 - x - (k - 1) * x) * 1.0 / (total * k)
        if y < 0:
            y = 0
        result.append(str(round(y * 100, 6)))
    s = ' '.join(result)
    print 'Case #%d: %s' % (i, s)


if __name__ == '__main__':
    i = int(raw_input())
    for x in xrange(i):
        compute(x + 1)
