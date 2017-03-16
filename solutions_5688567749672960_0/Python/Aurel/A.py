import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(100000000)

class memoized(object):
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
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
    def clear(self):
        self.cache = {}


def naive(i):
    if i == N:
        return 0

    if i <= 9:
        return N-i

    if store[i] == 0:
        return 1000000000

    if store[i] > 0:
        return store[i]

    store[i] = 0
    flipStr = str(i)[::-1]
    if flipStr[0] == '0':
        store[i] = 1 + naive(i+1)
    else:
        f = int(flipStr)
        store[i] = min(N-i, 2 + naive(f + 1))
    return store[i]

T = int(raw_input())
for testId in range(T):
    store = [-1 for i in xrange(1000001)]
    N = input()
    print "Case #{:d}: {:d}".format(testId+1, naive(1))
