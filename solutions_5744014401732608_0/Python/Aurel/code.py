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

def modPow(b, e, mod):
    res = 1
    b = b % mod
    while e > 0:
        if e%2 == 1:
            res = (res * b) % mod
        e = e // 2
        b = (b * b) % mod
    return res

def inputInts():
    return map(int, raw_input().split())



def highestPowerOf2(m):
    i = 0
    while pow(2, i) <= m:
        i += 1
    return i-1

def printGrid(g):
    for row in g:
        print ''.join(map(str, row))
    
T = int(raw_input())
for testId in range(T):
    B, M = inputInts()

    if B == 2:
        if M == 1:
            print "Case #{:d}: POSSIBLE".format(testId+1)
            print "01"
            print "00"
        else:
            print "Case #{:d}: IMPOSSIBLE".format(testId+1)
        continue

    if M > pow(2, B-2):
        print "Case #{:d}: IMPOSSIBLE".format(testId+1)
        continue

    print "Case #{:d}: POSSIBLE".format(testId+1)
    grid = [[0 for i in xrange(B)] for j in xrange(B)]


    for i in xrange(2, B+1):
        for j in xrange(i+1, B+1):
            grid[i-1][j-1] = 1

    if M == pow(2, B-2):
        grid[0][1:] = [1 for i in xrange(B-1)]
        printGrid(grid)
        continue

    while M > 0:
        i = highestPowerOf2(M)
        grid[0][B-2-i] = 1
        M -= pow(2, i)

    printGrid(grid)
