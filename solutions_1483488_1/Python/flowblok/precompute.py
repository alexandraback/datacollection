from collections import defaultdict
from itertools import product
import json
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

def precompute(n):
    d = defaultdict(list)

    k = 0

    for p in product(*([digits] * n)):
        p = ''.join(p)

#        if k % 10000 == 0:
#            print p
#        k += 1
#
#        if not (1000000 <= int(p) <= 2000000):
#            continue

        key = make_key(p)
        d[key].append(int(p))

    return [
        v
        for v in d.values()
        if len(v) > 1
    ]

#for i in xrange(1, 8):
#    d = precompute(i)
#    with open('%d.pre' % i, 'w') as f:
#        json.dump(d, f)

precomputed = {}

def solve(a, b):
    n = len(str(a))
    if n not in precomputed:
        with open('%d.pre' % n, 'rb') as f:
            precomputed[n] = json.load(f)

    total = 0
    for values in precomputed[n]:
        k = sum(1 for v in values if a <= v <= b)
        if k <= 1:
            continue
        pairs = (k - 1) * k / 2
        total += pairs
    return total

n = int(raw_input())
for i in xrange(1, n + 1):
    a, b = map(int, raw_input().split())
    print 'Case #%d:' % i, solve(a, b)
