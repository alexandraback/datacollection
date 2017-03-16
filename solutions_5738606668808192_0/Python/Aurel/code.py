import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

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


def inputInts():
    return map(int, raw_input().split())

@memoized
def findDivider(n):
    for i in xrange(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return i
    return False


T = int(raw_input()) # always 1
N, J = inputInts()
pows = [
    [pow(base, exp) for exp in xrange(N)]
    for base in xrange(11)
]

print "Case #1:"

found = 0
base2 = 1 + pows[2][N-1]

while found < J:
    s = "{0:b}".format(base2)
    # s always has the first and last bit set. Now we need to check the dividers in all bases
    valid = True
    dividers = [0 for i in xrange(11)]
    for base in xrange(2, 11):
        asBase = 0
        for i in xrange(N):
            if s[N-1-i] == '1':
                asBase += pows[base][i]
        dividers[base] = findDivider(asBase)
        if dividers[base] == False:
            valid = False
            break

    if valid:
        found += 1
        print s, " ".join([str(a) for a in dividers[2:]])

    # next valid input has to be odd (the 2^0 bit is always set)
    base2 += 2
