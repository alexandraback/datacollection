from __future__ import division, print_function

import fnmatch
import itertools
import sys



def gen(s):
    l = len(s)
    for i in xrange(10 ** l):
        n = i
        ns = str(i).rjust(l, '0')
        if fnmatch.fnmatch(ns, s):
            yield n, ns


def solve():
    c, j = read_array()
    mn = (10 ** len(c), 10 ** len(c), '', 10 ** len(c), '')
    for cn, cs in gen(c):
        for jn, js in gen(j):
            if abs(cn - jn) < mn[0]:
                mn = (abs(cn - jn), cn, cs, jn, js)
            elif abs(cn - jn) == mn[0]:
                if cn < mn[1]:
                    mn = (abs(cn - jn), cn, cs, jn, js)
                elif cn == mn[1]:
                    if jn < mn[3]:
                        mn = (abs(cn - jn), cn, cs, jn, js)
    return '{} {}'.format(mn[2], mn[4])


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
