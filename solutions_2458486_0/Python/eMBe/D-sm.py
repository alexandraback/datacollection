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

def main():
    t = gcj.token(int)
    for _ in xrange(t):
        k, n = gcj.tokens(2, int)
        keys = gcj.tokens(k, int)
        chests = []
        for _ in xrange(n):
            ti, ki = gcj.tokens(2, int)
            chests.append((ti, gcj.tokens(ki, int)))
        print gcj.case(),
        res = solve(keys, chests)
        if res:
            for x in res:
                print x,
            print
        else:
            print 'IMPOSSIBLE'

def solve(keys, chests):
    keys = collections.Counter(keys)
    total = keys.copy()
    needed = collections.Counter()
    for chest in chests:
        needed[chest[0]] += 1
        total.update(chest[1])
    return solve_(keys, set(), 0, chests, [])

def solve_(keys, memo, done, chests, cur):
    n = len(chests)
    if done == 2**n-1:
        return cur
    if done in memo:
        return None
    memo.add(done)
    for i in xrange(n):
        if done & (2**i):
            continue
        chest = chests[i]
        if keys[chest[0]] <= 0:
            continue
        cur.append(i+1)
        new_keys = keys.copy()
        new_keys[chest[0]] -= 1
        new_keys.update(chest[1])
        res = solve_(new_keys, memo, done | (2**i), chests, cur)
        if res:
            return res
        cur.pop()
    return None

main()
