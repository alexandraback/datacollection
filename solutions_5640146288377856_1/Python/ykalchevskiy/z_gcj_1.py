from __future__ import print_function
import sys


def solve():
    """Main."""
    r, c, w = read_int_array()
    if r == 1:
        if c == w:
            return c
        elif w == 1:
            return c
        else:
            return (c / w) + (w - 1) + bool(c % w)
        # return (c / w) + (w - 1) + bool(c % w)
    else:
        if c == w:
            return c  + (r - 1)
        elif w == 1:
            return c  * r
        else:
            return (c / w)  * r  + (w - 1) + bool(c % w)


def main():
    for test in xrange(1, read_int() + 1):
        write('Case #{}: {}'.format(test, solve()))


def bye(message=None):
    if message is not None:
        write(message)
    sys.exit()


def read(func=None):
    a = sys.stdin.readline().rstrip('\n')
    return a if func is None else func(a)


def read_array(func=None, sep=None, maxsplit=-1):
    array = read().split(sep, maxsplit)
    return array if func is None else [func(a) for a in array]


def read_int():
    return read(int)


def read_int_array(sep=None, maxsplit=-1):
    return read_array(int, sep, maxsplit)


def write(*args, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    sys.stdout.write(sep.join(str(a) for a in args) + end)
    sys.stdout.flush()


def write_array(array, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    sys.stdout.write(sep.join(str(a) for a in array) + end)


main()
