#!/usr/bin/env python

import math
import multiprocessing
import itertools
import sys

from ipdb import launch_ipdb_on_exception


def digits(num):
    return int(math.ceil(math.log10(num+.1)))

def palindromes(base, upper):
    while True:
        digs = digits(base)
        mult = 10**(digs / 2)
        prefix = base / mult
        mid = 9
        mid_mult = 0
        if digs % 2 == 1:
            mid = prefix % 10
            prefix /= 10
            mid_mult = mult
            mult *= 10
        for m in xrange(mid, 10):
            num = (prefix * mult) + (m * mid_mult) + int(str(prefix)[::-1])
            if base <= num <= upper:
                yield num
        prefix += 1
        base = (prefix * mult) + int(str(prefix)[::-1])
        if base > upper:
            break

def is_palindrome(thing):
    s = str(thing)
    return s[:len(s)/2] == s[:-(len(s) + 1)/2:-1]


class TestCase(object):
    """
    Template for solving test cases
    """
    def __init__(self, idx):
        self.idx = idx
        self.parse()

    def parse(self):
        """
        Called synchronously in order to parse data from stdin
        """
        self.a, self.b = [int(num) for num in raw_input().split()]

    @property
    def result(self):
        """
        IMPLEMENT ME
        """
        with launch_ipdb_on_exception():
            n = 0
            for pal in palindromes(int(math.sqrt(self.a) + .5),
                                   int(math.sqrt(self.b))):
                if self.a <= pal**2 <= self.b and is_palindrome(pal**2):
                    n += 1
            return n

    def __str__(self):
        return 'Case #{self.idx}: {self.result}'.format(self=self)


if __name__ == '__main__':
    solvers = []
    ncases = input()
    for i in xrange(ncases):
        solvers.append(TestCase(i+1))

    if 'debug' in sys.argv:
        pool = itertools
    else:
        pool = multiprocessing.Pool(4)

    for soln in pool.imap(str, solvers):
        print soln
    pool.close()
    pool.join()
