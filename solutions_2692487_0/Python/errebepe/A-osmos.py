#/usr/bin/env python2.7
"""Osmos"""
from __future__ import print_function

"""
Output:

Number of operations to make Osmos solvable
"""

# - On large dataset: biggest mote size is (100 * 10**6 == 10**8) + 10**6
# - is it worth it to sum motes one by one, from armin backwards? N <= 100.

import sys
import bisect
import itertools
longrange = lambda start, stop: iter(itertools.count(start).next, stop)

DEBUG_MODE = False

def DEBUG(*args, **kwargs):
    if DEBUG_MODE:
        print(*args, **kwargs)


def get_max_absorbable_mote(armin, motes, stop_at):
    "Returns index, max absorbable mote"
    max_absorbable_mote = armin
    if max_absorbable_mote > stop_at:
        return len(motes), max_absorbable_mote

    index = bisect.bisect_left(motes, max_absorbable_mote)
    prev_index = 0
    while index != prev_index and index != len(motes) and max_absorbable_mote <= stop_at:
        DEBUG("motes({}), prev_index({}), index({}), max_absorbable_mote({})".format(motes, prev_index, index, max_absorbable_mote))
        max_absorbable_mote += sum(motes[prev_index:index])
        prev_index = index
        index = bisect.bisect_left(motes, max_absorbable_mote, prev_index, len(motes))
        DEBUG("index({}), prev_index({}), max_absorbable_mote({}), stop_at({})".format(index, prev_index, max_absorbable_mote, stop_at))

    return index, max_absorbable_mote


def num_ops(armin, motes, limit=None):
    # Returns number of ops to make Osmos solvable, or limit, whichever is lowest.
    # Assumes sorted motes
    DEBUG("armin({}), motes({}), limit({})".format(armin, motes, limit))

    if not motes:
        return 0

    if limit == 0:
        return 0

    # Already biggest mote
    if armin > motes[-1]:
        DEBUG("Biggest mote!")
        return 0

    index, max_absorbable_mote = get_max_absorbable_mote(armin, motes, stop_at=motes[-1])

    DEBUG("index({}), max_absorbable_mote({})".format(index, max_absorbable_mote))

    # Already capable of absorbing them all
    if max_absorbable_mote > motes[-1]:
        DEBUG("Absorb them all!")
        return 0

    # First try: add one mote
    if max_absorbable_mote > 1 and max_absorbable_mote + max_absorbable_mote - 1 > motes[-1]:
        DEBUG("Solve by adding one mote")
        return 1

    # Second try: remove biggest mote
    if len(motes) > 1 and max_absorbable_mote > motes[-2]:
        DEBUG("Solve by removing biggest mote")
        return 1

    # No? Ok, so at least one operation is needed

    # Number of operations after adding one (biggest possible) mote
    n1 = None
    if max_absorbable_mote > 1:
        n1 = 1 + num_ops(max_absorbable_mote + max_absorbable_mote - 1, motes[index:],
                         limit = limit - 1 if limit is not None else limit)

    # Now number of operations after removing biggest mote
    n2 = 1 + num_ops(max_absorbable_mote, motes[index:-1],
                     limit = n1 - 1 if n1 is not None else
                     (limit - 1 if limit is not None else limit))

    DEBUG("n1({}), n2({})".format(n1, n2))
    if n1 is None or n2 < n1:
        return n2
    return n1


def decide(armin, motes):
    motes.sort()
    num = num_ops(armin, motes)
    return num

def run(infile):
    f = open(infile)
    num = int(f.readline())
    for i in xrange(num):
        armin, n_motes = [int(j) for j in f.readline().split()]
        motes = [int(j) for j in f.readline().split()]
        assert len(motes) == n_motes
        print('Case #{count}: {}'.format(decide(armin, motes), count=i+1))


if __name__ == '__main__':
    run(sys.argv[1])
