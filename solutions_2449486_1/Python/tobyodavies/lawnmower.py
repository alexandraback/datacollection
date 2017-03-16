#!/usr/bin/env python

import multiprocessing
import itertools as it
import sys

from ipdb import launch_ipdb_on_exception


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
        self.n, self.m = [int(s)
                          for s in raw_input().split()]
        self.grid = [[int(c) for c in raw_input().strip().split()]
                     for _ in xrange(self.n)]

    @property
    def rows(self):
        return self.grid

    @property
    def columns(self):
        return [[self.grid[i][j] for i in xrange(self.n)]
                for j in xrange(self.m)]

    @property
    def diagonals(self):
        return [[self.grid[i][j0+di*i]
                 for i in xrange(4)]
                for j0, di in [(0, 1), (3, -1)]]

    @property
    def result(self):
        """
        A pattern can be cut if for every square
        it's row is <= in height or it's column <= in height
        """
        for i, j in it.product(xrange(self.n), xrange(self.m)):
            ## print i, j, self.grid[i][j]
            ## print [cell for cell in self.rows[i] if cell > self.grid[i][j]]
            ## print [cell for cell in self.columns[j] if cell > self.grid[i][j]]
            if (any(cell > self.grid[i][j] for cell in self.rows[i])
                and
                any(cell > self.grid[i][j] for cell in self.columns[j])):
                return "NO"
        return "YES"

    def __str__(self):
        return 'Case #{self.idx}: {self.result}'.format(self=self)


if __name__ == '__main__':
    solvers = []
    ncases = input()
    for i in xrange(ncases):
        solvers.append(TestCase(i+1))

    if 'debug' in sys.argv:
        pool = it
    else:
        pool = multiprocessing.Pool(4)

    for soln in pool.imap(str, solvers):
        print soln

    if 'debug' not in sys.argv:
        pool.close()
        pool.join()
