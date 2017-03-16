#!/usr/bin/python
# coding=utf8
import sys
from numpy import cross, dot, multiply, add, subtract
from numpy.linalg import norm
from itertools import permutations, combinations
import collections
import functools

hide_dots = len(sys.argv) > 1 and sys.argv[1] == "hide_dots"


def dbg(*args, **kwargs):
    first = True
    for i in args:
        if first:
            first = False
        else:
            sys.stderr.write(" ")
        sys.stderr.write(str(i))
    if 'no_line_jump' in kwargs and kwargs['no_line_jump']:
        pass
    else:
        sys.stderr.write("\n")


class memoized(object):
    '''Decorator. Caches a function's return value each time it is called.
    If called later with the same arguments, the cached value is returned
    (not reevaluated).
    '''
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        if not isinstance(args, collections.Hashable):
            return self.func(*args)
        if args in self.cache:
            return self.cache[args]
        else:
            value = self.func(*args)
            self.cache[args] = value
            return value
    def __repr__(self):
        '''Return the function's docstring.'''
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)


def main():
    data = sys.stdin
    nb = int(data.readline())
    for icase in xrange(nb):
        if not hide_dots:
            dbg(".", no_line_jump=True)

        A, B, K = map(int, data.readline().split())

        # combien de xor entre deux nombre donne un nombre plus petit que K
        # il faut le traiter bit par bit

        count = 0
        for a in xrange(A):
            for b in xrange(B):
                amodb = a & b
                if amodb < K:
                    #print bin(a)[2:] + "^" + bin(b)[2:] + "=" + bin(amodb)[:2]
                    count += 1


        res = str(count)
        print "Case #%d: %s" % (icase + 1, res)


if __name__ == "__main__":
    main()
