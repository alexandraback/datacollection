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

def gen(comb, n, cnt, cur=1, i=0):
    if i == n:
        cnt[cur] += 1
        return
    gen(comb, n, cnt, cur, i+1)
    gen(comb, n, cnt, cur*comb[i], i+1)

def solve(n, m, data, _memo={}, _combs=[]):
    fact = [1]
    for i in xrange(1, 42):
        fact.append(i * fact[-1])
    if not _combs:
        _combs.extend(itertools.combinations_with_replacement(xrange(2, m+1), n))
    if not _memo:
        for comb in _combs:
            s = collections.Counter(comb)
            x = fact[len(s)]
            for i in s.itervalues():
                x //= fact[i]
            if x < 2:
                continue
            cnt = collections.defaultdict(int)
            gen(comb, n, cnt, x)
            _memo[comb] = cnt

    bests = -1
    best = None
    for comb in _memo.iterkeys():
        score = 1
        cnt = _memo[comb]
        cnt_get = cnt.get
        for x in data:
            score *= cnt_get(x, 0)
            if not score:
                break
        if score > bests:
            bests = score
            best = comb
    return best

def main():
    t = gcj.token(int)
    for _ in xrange(t):
        R, N, M, K = gcj.tokens(4, int)
        print gcj.case()
        for _ in xrange(R):
            data = gcj.tokens(K, int)
            print ''.join(str(x) for x in sorted(solve(N, M, data)))

main()
