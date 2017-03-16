from __future__ import division, print_function

import collections
import itertools
import sys


NUMBERS = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
NUMBERS_COUNTERS = map(collections.Counter, NUMBERS)


def get_numbers(c, n, p):
    t = c[p]
    for _ in times(c[p]):
        c.subtract(NUMBERS_COUNTERS[int(n)])
    return [n] * t


def solve():
    s = read()
    c = collections.Counter(s)
    numbers = []
    numbers.extend(get_numbers(c, '0', 'Z'))
    numbers.extend(get_numbers(c, '2', 'W'))
    numbers.extend(get_numbers(c, '8', 'G'))
    numbers.extend(get_numbers(c, '6', 'X'))
    numbers.extend(get_numbers(c, '7', 'S'))
    numbers.extend(get_numbers(c, '5', 'V'))
    numbers.extend(get_numbers(c, '4', 'F'))
    numbers.extend(get_numbers(c, '9', 'I'))
    numbers.extend(get_numbers(c, '1', 'O'))
    numbers.extend(get_numbers(c, '3', 'T'))
    return ''.join(sorted(numbers))


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
