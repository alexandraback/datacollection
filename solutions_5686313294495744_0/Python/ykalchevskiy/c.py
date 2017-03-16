from __future__ import division, print_function

import itertools
import sys
from collections import defaultdict

"""
3
5
a b
c d
e f
c b
e d
7
a b
c d
e f
c b
e d
a d
c f
6
a b
c d
e f
c b
e d
a d
"""


def solve():
    n = read_int()
    fm = defaultdict(set)
    sm = defaultdict(set)
    for _ in times(n):
        f, s = read_array()
        fm[f].add(s)
        sm[s].add(f)
    r = 0
    import pprint
    # pprint.pprint(dict(fm))
    # pprint.pprint(dict(sm))
    for f in fm.keys():
        for s in list(fm[f]):
        # for s in sm.keys():
            if s in fm[f] and len(fm[f]) > 1 and len(sm[s]) > 1:
                # print(f, s)
                r += 1
                fm[f].remove(s)
                sm[s].remove(f)
    return r

"""
1
16
WH DJ
UP IU
OG YZ
CZ HD
UP HD
BQ DJ
OG VK
ZD UX
WR OK
WV YZ
CZ ON
WH HD
WH YZ
NF UX
ZD DO
WR DK
"""

"""
1
10
UP IU
BQ DJ
OG VK
WR OK
WV YZ
CZ ON
WH HD
NF UX
ZD DO
WR DK
"""


def main():
    for i in xrange(1, read_int() + 1):
        write('Case #{}: {}'.format(i, solve()))


def bye(message=None):
    if message is not None:
        write(message)
    sys.exit()


def times(n):
    return itertools.repeat(None, n)


def read(func=None):
    a = sys.stdin.readline().rstrip('\n')
    return a if func is None else func(a)


def read_array(func=None, sep=None, max_split=-1):
    array = read().split(sep, max_split) if sep != '' else list(read())
    return array if func is None else [func(a) for a in array]


def read_2d_array(n, func=None, sep=None, max_split=-1):
    return [read_array(func, sep, max_split) for _ in times(n)]


def read_int():
    """:rtype: int"""
    return read(int)


def read_int_array(sep=None, max_split=-1):
    """:rtype: list[int]"""
    return read_array(int, sep, max_split)


def read_int_2d_array(n, sep=None, max_split=-1):
    """:rtype: list[list[int]]"""
    return read_2d_array(n, int, sep, max_split)


def write(*args, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    sys.stdout.write(sep.join(str(a) for a in args) + end)


def write_array(array, **kwargs):
    write(*array, **kwargs)


def write_2d_array(array, **kwargs):
    [write_array(a, **kwargs) for a in array]


def _main_():
    name = ''
    names = ''
    if name or names:
        in_name = name + '.in' if name else 'input.txt'
        out_name = name + '.out' if name else 'output.txt'
        stdin = sys.stdin
        stdout = sys.stdout
        sys.stdin = open(in_name)
        sys.stdout = open(out_name, 'w')
        main()
        sys.stdin.close()
        sys.stdout.close()
        sys.stdin = stdin
        sys.stdout = stdout
    else:
        main()


_main_()
