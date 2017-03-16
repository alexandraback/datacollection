# encoding: UTF-8

from __future__ import absolute_import, division

from future_builtins import *
range = xrange

import collections
import itertools
import string
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
        return line[:i].tobytes()

    @classmethod
    def tokens(cls, cnt, conv=identity):
        return [cls.token(conv) for _ in range(cnt)]

    current_case = 0

    @classmethod
    def case(cls):
        cls.current_case += 1
        return b'Case #{}:'.format(cls.current_case)

tmap = {' ': ' '}

def init():
    tin = '''
    y qee
    ejp mysljylc kd kxveddknmc re jsicpdrysi
    rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
    de kr kd eoya kw aej tysr re ujdr lkgc jv
    '''.replace(' ', '').replace('\n', '')
    tout = '''
    a zoo
    our language is impossible to understand
    there are twenty six factorial possibilities
    so it is okay if you want to just give up
    '''.replace(' ', '').replace('\n', '')

    assert len(tin) == len(tout)
    for a, b in zip(tin, tout):
        if a in tmap:
            assert tmap[a] == b
        else:
            tmap[a] = b
    tmapr = dict((b, a) for (a, b) in tmap.iteritems())
    missing = set(a for a in string.ascii_lowercase if a not in tmap)
    missingr = set(a for a in string.ascii_lowercase if a not in tmapr)
    assert len(missing) == len(missingr) <= 1
    if missing:
        tmap[next(iter(missing))] = next(iter(missingr))

init()

def translate(s):
    return ''.join(tmap[x] for x in s)

def main():
    t = gcj.line(int)
    for _ in xrange(t):
        line = gcj.line()
        print gcj.case(), translate(line)

main()
