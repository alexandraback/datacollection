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

def solve():
    a, b, k = gcj.tokens(3, int)
    return go(a-1, b-1, k-1)

memo = {}
def go(a, b, k, p=2**32):
    if max(a, b) <= 10:
        return sum(q&w <= k for q in xrange(a+1) for w in xrange(b+1))
    if (a, b, k, p) in memo:
        return memo[a, b, k, p]
    res = 0
    if k & p:
        res += min(a+1, p) * min(b+1, p)
        if a & p:
            res += (a - p + 1) * min(b+1, p)
        if b & p:
            res += (b - p + 1) * min(a+1, p)
        if a & p and b & p:
            res += go(a^p, b^p, k^p, p//2)
    else:
        res += go(min(a, p-1), min(b, p-1), k, p//2)
        if a & p:
            res += go(a^p, min(b, p-1), k, p//2)
        if b & p:
            res += go(min(a, p-1), b^p, k, p//2)
    memo[a, b, k, p] = res
    return res

def main():
    sys.setrecursionlimit(10000)
    t = gcj.token(int)
    for _ in xrange(t):
        print gcj.case(), solve()
        sys.stdout.flush()

main()
