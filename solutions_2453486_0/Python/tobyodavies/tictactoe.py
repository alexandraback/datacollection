#!/usr/bin/env python

import multiprocessing
import itertools
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
        self.grid = [raw_input().strip()
                     for _ in xrange(4)]
        try:
            raw_input()
        except:
            pass
    @property
    def rows(self):
        return self.grid

    @property
    def columns(self):
        return [[self.grid[j][i] for j in xrange(4)]
                for i in xrange(4)]

    @property
    def diagonals(self):
        return [[self.grid[i][j0+di*i]
                 for i in xrange(4)]
                for j0, di in [(0, 1), (3, -1)]]

    def winner(self, seq):
        for P in ('X', 'O'):
            if all(cell in (P, 'T')
                   for cell in seq):
                return P

    @property
    def result(self):
        with launch_ipdb_on_exception():
            if any('.' in row
                   for row in self.grid):
                status = "Game has not completed"
            else:
                status = "Draw"
            for seq in self.rows + self.columns + self.diagonals:
                if self.winner(seq):
                    return self.winner(seq)+" won"
            return status

    def __str__(self):
        return 'Case #{self.idx}: {self.result}'.format(self=self)


if __name__ == '__main__':
    solvers = []
    ncases = input()
    for i in xrange(ncases):
        solvers.append(TestCase(i+1))
    #print locals()

    if 'debug' in sys.argv:
        pool = itertools
    else:
        pool = multiprocessing.Pool(4)

    for soln in pool.imap(str, solvers):
        print soln
    pool.close()
    pool.join()
