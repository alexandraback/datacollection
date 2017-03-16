#!/usr/bin/env python

import collections
import multiprocessing
import itertools
import sys

from ipdb import launch_ipdb_on_exception

import pulp as p


def trans(graph):
    cache = {(x, y): -1
             for (x,y) in graph}
    cache.extend({(y, x): 1
                  for (x,y) in graph})
    def cmp(x, y):
        if (x, y) not in cache:
            if any(cmp(i, y)
                   for (_x, i) in graph
                   if _x == x
                   and cmp(i, y)):
                cache[x, y] = -1
                cache[y, x] = 1
            elif any(cmp(y, i)
                     for (_x, i) in graph
                     if _x == x
                     and cmp(i, x)):
                cache[x, y] = 1
                cache[y, x] = -1
            else:
                cache[x, y] = 0
                cache[y, x] = 0
        return cache[x, y]


class TestCase(object):
    """
    Template for solving test cases
    """
    def __init__(self, idx):
        self.idx = idx
        self.nogoods = {}
        self.parse()

    def parse(self):
        """
        Called synchronously in order to parse data from stdin
        """
        self.nkeys, self.nchests = [int(n) for n in raw_input().split()]
        keys = [int(n) for n in raw_input().split()]
        self.init_keys = collections.Counter({k: keys.count(k) for k in keys})
        self.chest_reqs = {}
        self.chest_keys = {}

        for i in xrange(self.nchests):
            ints = [int(n) for n in raw_input().split()]
            self.chest_reqs[i] = ints[0]
            keys = ints[2:]
            self.chest_keys[i] = collections.Counter({k: keys.count(k) for k in keys})

    def open(self, keys, chest):
        keys = collections.Counter(keys)
        keys[self.chest_reqs[chest]] -= 1
        keys.update(self.chest_keys[chest])
        return keys

    def sufficient_keys(self, keys, opened):
        # a specific instance of relaxed planning/regression
        # assuming order is irrelevant, can we still assign a key to each lock?
        if any((keys[k] + sum(self.chest_keys[c][k]
                              for c in xrange(self.nchests)
                              if c not in opened))
                <
                sum(1
                    for c in xrange(self.nchests)
                    if (c not in opened
                        and
                        self.chest_reqs[c] == k))
               for k in xrange(self.nkeys)):
            return False
        return True


    def solve_plan(self, seq=None, keys=None, nogoods=None):

        keys = collections.Counter(self.init_keys) if keys is None else keys
        seq = [] if seq is None else seq
        nogoods = set([]) if nogoods is None else nogoods

        opened = frozenset(seq)
        if opened in nogoods:
            return

        if len(seq) == self.nchests:
            return seq
        for c in xrange(self.nchests):
            if c not in seq and keys[self.chest_reqs[c]] > 0:
                soln = self.solve_plan(seq + [c],
                                       self.open(keys, c),
                                       nogoods)
                if soln is not None:
                    return soln
                else:
                    nogoods.add(frozenset(seq))

    @property
    def result(self):
        """
        Use multi-commodity network flow to calculate a partial order
        """
        with launch_ipdb_on_exception():
            order = None
            if self.sufficient_keys(self.init_keys, opened=set([])):
                order = self.solve_plan()
            if order is None:
                return "IMPOSSIBLE"
            return ' '.join(str(o+1) for o in order)

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
