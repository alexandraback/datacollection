import sys, itertools
from collections import defaultdict
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

def multiply(x, y):
    # i * j = k; i * i = -1, ...
    sign = 1
    if x.startswith('-'):
        sign *= -1
        x = x[1:]
    if y.startswith('-'):
        sign *= -1
        y = y[1:]
    ret = _multiply_inner(x, y)
    if ret.startswith('-'):
        sign *= -1
        ret = ret[1:]

    if sign == -1:
        if ret.startswith('-'):
            ret = ret[1:]
        else:
            ret = '-' + ret

    return ret

def _multiply_inner(x, y):
    if x == '1': return y
    if y == '1': return x
    if x == y: return '-1'
    if (x, y) in [('i', 'j'), ('j', 'k'), ('k', 'i')]:
        return _find_other(x, y)
    return '-' + _find_other(x, y)

def _find_other(x, y):
    for possible in 'ijk':
        if possible in (x, y):
            continue
        return possible

def build_table():
    global _mul
    _mul = dict()
    operands = [
        '1', 'i', 'j', 'k',
        '-1', '-i', '-j', '-k'
    ]
    for op1, op2 in itertools.product(operands, operands):
        _mul[(op1, op2)] = multiply(op1, op2)

    return _mul

build_table()

def mul(x, y):
    return _mul[(x, y)]

for no_t in xrange(1, read_int() + 1):
    L, X = read_ints()
    s = raw_input()
    n = len(s)

    prefix = [None] * n
    prefix[0] = s[0]
    for i in xrange(1, n):
        prefix[i] = mul(prefix[i - 1], s[i])

    total = '1'
    for k in xrange(X % 4):
        total = mul(total, prefix[n - 1])

    if total != '-1':
        # b/c ijk = -1
        print 'Case #%d: %s' % (no_t, 'NO')
        continue

    suffix = [None] * n
    suffix[n - 1] = s[n - 1]
    for i in xrange(n - 2, -1, -1):
        suffix[i] = mul(s[i], suffix[i + 1])

    #
    # Find shortest prefix = i
    #
    cur = '1'
    shortest_prefix = None
    for k in xrange(min(4, X)):
        for i in xrange(n):
            if mul(cur, prefix[i]) == 'i' and shortest_prefix is None:
                shortest_prefix = (k, i)
        cur = mul(prefix[n - 1], cur)

    #
    # Find shortest suffix = k
    #
    cur = '1'
    shortest_suffix = None
    for k in range(X - 1, max(X - 5, -1), -1):
        for i in reversed(xrange(n)):
            if mul(suffix[i], cur) == 'k' and shortest_suffix is None:
                shortest_suffix = (k, i)
        cur = mul(suffix[n - 1], cur)

    if shortest_suffix and shortest_prefix and (shortest_prefix < shortest_suffix):
        ans = 'YES'
    else:
        ans = 'NO'

    print 'Case #%d: %s' % (no_t, ans)
