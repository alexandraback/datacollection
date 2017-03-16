# encoding: UTF-8

from __future__ import absolute_import, division

from future_builtins import *
range = xrange

import collections
import itertools
import sys

class gcj:
    IN = sys.stdin
    buf = None

    identity = lambda x: x

    @classmethod
    def _read_line_raw(cls):
        if cls.buf:
            res = cls.buf
            cls.buf = None
        else:
            res = cls.IN.readline()
        if not res:
            raise EOFError()
        return res

    @classmethod
    def _read_line_view(cls):
        line = cls._read_line_raw()
        if not isinstance(line, memoryview):
            line = memoryview(line)
        return line

    @classmethod
    def _read_line(cls):
        line = cls._read_line_raw()
        if isinstance(line, memoryview):
            line = line.tobytes()
        return line

    @classmethod
    def line(cls, conv=identity):
        line = cls._read_line()
        return conv(line.rstrip(b'\r\n'))

    @classmethod
    def splitline(cls, conv=identity):
        line = cls._read_line()
        return [conv(x) for x in line.split()]

    @classmethod
    def whitespace(cls):
        line = None
        while not line:
            line = cls._read_line_raw()
            i = 0
            l = len(line)
            while i < l and line[i].isspace():
                i += 1
            line = memoryview(line)[i:]
        cls.buf = line

    @classmethod
    def token(cls, conv=identity):
        cls.whitespace()
        line = cls._read_line_view()
        i = 0
        l = len(line)
        while i < l and not line[i].isspace():
            i += 1
        cls.buf = line[i:] if i < l else None
        return conv(line[:i].tobytes())

    @classmethod
    def tokens(cls, cnt, conv=identity):
        return [cls.token(conv) for _ in range(cnt)]

    current_case = 0

    @classmethod
    def case(cls):
        cls.current_case += 1
        return b'Case #{}:'.format(cls.current_case)

q1 = (1, 0, 0, 0)
qi = (0, 1, 0, 0)
qj = (0, 0, 1, 0)
qk = (0, 0, 0, 1)

def qmul((a1, b1, c1, d1), (a2, b2, c2, d2)):
    return (a1*a2 - b1*b2 - c1*c2 - d1*d2,
            a1*b2 + b1*a2 + c1*d2 - d1*c2,
            a1*c2 - b1*d2 + c1*a2 + d1*b2,
            a1*d2 + b1*c2 - c1*b2 + d1*a2)

def qminus((a, b, c, d)):
    return (-a, -b, -c, -d)

for a in (q1, qi, qj, qk):
    assert qmul(q1, a) == qmul(a, q1) == a
    for b in (q1, qi, qj, qk):
        for c in (q1, qi, qj, qk):
            assert qmul(a, qmul(b, c)) == qmul(qmul(a, b), c)

def qpow(q, n):
    if n == 0:
        return q1
    if n == 1:
        return q
    res = qpow(q, n//2)
    res = qmul(res, res)
    if n % 2 == 1:
        res = qmul(res, q)
    return res

def qmuls(qs):
    return reduce(qmul, qs)

def qstr(q):
    if q == q1:
        return '1'
    if q == qi:
        return 'i'
    if q == qj:
        return 'j'
    if q == qk:
        return 'k'
    return '-' + qstr(qminus(q))

def solve():
    l, x = gcj.tokens(2, int)
    chars = gcj.token()
    cmap = {'i': qi, 'j': qj, 'k': qk}
    assert len(chars) == l
    nums = [cmap[c] for c in chars]
    total = qpow(qmuls(nums), x)
    if total != qmuls((qi, qj, qk)):
        return False
    x = min(x, 12)
    nums *= x
    cur = q1
    i = 0
    while cur != qi and i < len(nums):
        cur = qmul(cur, nums[i])
        i += 1
    cur = q1
    while cur != qj and i < len(nums):
        cur = qmul(cur, nums[i])
        i += 1
    return i < len(nums)

def main():
    sys.setrecursionlimit(10000)
    t = gcj.token(int)
    for _ in xrange(t):
        print gcj.case(), 'YES' if solve() else 'NO'
        sys.stdout.flush()

main()
