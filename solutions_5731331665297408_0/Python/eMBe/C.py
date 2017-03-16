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
    n, m = gcj.tokens(2, int)
    zips = gcj.tokens(n, int)
    neigh = [set() for _ in xrange(n)]
    for _ in xrange(m):
        a, b = gcj.tokens(2, int)
        neigh[a-1].add(b-1)
        neigh[b-1].add(a-1)
    Z = lambda v: zips[v]
    s = min(xrange(n), key=Z)
    res = [s]
    left = set(xrange(n)) - {s}
    live = set(neigh[s])
    while left:
        for w in left:
            assert reachable(w, neigh, live, left.copy())
        v = min(live, key=Z)
        process(v, neigh, res, live, left, Z)
    return ''.join(str(zips[v]) for v in res)

def process(v, neigh, res, live, left, Z):
    if v not in left:
        return
    res.append(v)
    if v in live:
        live.remove(v)
    left.remove(v)
    ok = True
    q = sorted(neigh[v] & left, key=Z)
    todo = []
    for w in q:
        if all(x in todo or Z(x) >= Z(w) for x in live):
            todo.append(w)
        elif not reachable(w, neigh, live | set(todo), left.copy()):
            ok = False
            break
    live.update(neigh[v] & left)
    if ok:
        for w in todo:
            process(w, neigh, res, live, left, Z)
    else:
        for w in q:
            process(w, neigh, res, live, left, Z)

def reachable(v, neigh, live, left):
    if v not in left:
        return False
    if v in live:
        return True
    left.remove(v)
    for w in neigh[v]:
        if reachable(w, neigh, live, left):
            return True
    return False

def main():
    sys.setrecursionlimit(10000)
    t = gcj.token(int)
    for _ in xrange(t):
        print gcj.case(), solve()
        sys.stdout.flush()

main()
