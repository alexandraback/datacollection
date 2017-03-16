from collections import defaultdict
from itertools import product
from string import digits

def make_key(p):
    """
    >>> make_key('111')
    '111'
    >>> make_key('121')
    '112'
    >>> make_key('312')
    '123'
    >>> make_key('321')
    '132'
    >>> make_key('1312')
    '1213'
    >>> make_key('2131')
    '1213'
    """
    return sorted(
        p[i:] + p[:i]
        for i in xrange(len(p))
    )[0]

def solve(minimum, maximum):
    n = len(str(minimum))

    d = defaultdict(int)

    for p in product(*([digits] * n)):
        p = ''.join(p)
        key = make_key(p)

        if minimum <= int(p) <= maximum:
            d[key] += 1

    total = 0
    for key, value in d.iteritems():
        if value <= 1:
            continue
        pairs = (value - 1) * value / 2
        total += pairs
    return total

n = int(raw_input())
for i in xrange(1, n + 1):
    a, b = map(int, raw_input().split())
    print 'Case #%d:' % i, solve(a, b)
