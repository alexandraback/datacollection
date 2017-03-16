#!/usr/bin/env python

import multiprocessing
import itertools
import sys

from ipdb import launch_ipdb_on_exception


def parse(*args):
    default = args[-1] if args else int
    return [ctor(x)
            for ctor, x in itertools.izip_longest(args,
                                                  raw_input().strip().split(),
                                                  fillvalue=default)]


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
        self.init, _ = parse()
        self.others = sorted(parse())
        self.dynprog = {}
        self.reason = {}

    def min_ops(self, idx, size, depth=0):
        for idx in xrange(idx, len(self.others)):
            key = (idx, size)
            if key not in self.dynprog:
                #print idx, size, depth
                if (idx >= len(self.others) or
                    (size > self.others[idx])):
                    self.reason[key] = ['Size %d: consume next at %d' % (size, idx)]
                    size += self.others[idx]
                    continue
                elif size > 1:
                    # either skip next or add 1 mote of size-1
                    add_mote_ops = self.min_ops(idx, size * 2 - 1, depth+1) + 1
                    skip_next_ops = self.min_ops(idx + 1, size, depth+1) + 1
                    if add_mote_ops < skip_next_ops:
                        self.reason[key] = ['Size %d: add mote at %d' % (size,idx)] + self.reason.get((idx, size*2-1), ['?'])
                    else:
                        self.reason[key] = ['Size %d: skip at %d (of size %d)' % (size,idx,self.others[idx])] + self.reason.get((idx + 1, size), ['?'])
                    self.dynprog[key] = min(add_mote_ops, skip_next_ops)
                    return self.dynprog[key]
                else:
                    self.reason[key] = ['Size %d: skip all from %d'%(size, idx)]
                    self.dynprog[key] = len(self.others) - idx
                    return self.dynprog[key]
            return self.dynprog[key]
        return 0

    @property
    def result(self):
        """
        IMPLEMENT ME
        """
        with launch_ipdb_on_exception():
            #print self.init, self.others
            ret = self.min_ops(0, self.init)
            #print self.reason[0, self.init]
            return ret

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
