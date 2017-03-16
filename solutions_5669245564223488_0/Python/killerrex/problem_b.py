#!/usr/bin/env python3
# coding=utf-8

"""
Problem 2 for Google CodeJam 2014, Round 1C

Author: A. Ayala
killerrex@gmail.com
"""

import sys
from functools import total_ordering
from itertools import permutations

MODULO = 1000000007

@total_ordering
class Cluster(object):
    """
    Represent a wagon/group of wagons
    """
    def __init__(self, txt):
        """
        Split the initial wagon in extremes + internals
        """
        if txt is None:
            self.left = None
            self.right = None
            self.combinations = None
            self.internal = None
        else:
            self.left = txt[0]
            self.right = txt[-1]
            self.internal = txt[1:-1]
            self.combinations = 1

    def compatible(self, other):
        """
        Check if this element is compatible with the other
        if any extreme is internal to the other, not compatible...
        """
        if self.left in other.internal and other.right != self.left:
            return False

        if self.right in other.internal and other.left != self.right:
            return False
        return True

    def __eq__(self, other):
        """
        Consider equal only if both extremes are equal
        """
        return self.left == other.left and self.right == other.right

    def __lt__(self, other):
        """
        Sort first by left, after by right
        """
        if self.left == other.left:
            return self.right < other.right
        else:
            return self.left < other.left

    def reduce(self, other):
        """
        Convert 2 wagons in 1, from the right of self
        """
        if self.right != other.left:
            return None
        # Ok, can combine
        new = Cluster(None)
        new.left = self.left
        new.right = other.right
        new.combinations = self.combinations * other.combinations
        return new

    def is_aa_wagon(self):
        return self.left == self.right

    def __str__(self):
        if self.internal is None:
            return "{0.left}__{0.combinations}__{0.right}".format(self)
        else:
            return "{0.left}__{0.internal}__{0.right}".format(self)


def solution(lst):
    """
    Solve for the lst of strings
    """
    lst = [Cluster(s) for s in lst]

    # Check compatibility
    for k in range(len(lst)):
        # Check if this element is compatible with all others
        for l in range(len(lst)):
            if k == l:
                continue
            if not lst[k].compatible(lst[l]):
                return 0
    for k in range(len(lst)):
        lst[k].internal = None

    # Now sort the elements
    lst.sort()

    # Cluster first all the repeated letters elements
    # As they are sorted, any a-a cluster shall be continuous
    while len(lst) > 1:
        for k in range(len(lst)-1):
            if not lst[k].is_aa_wagon():
                continue
            # Check if the next is compatible
            if lst[k+1].is_aa_wagon() and lst[k+1].right == lst[k].left:
                new = lst[k].reduce(lst[k+1])
                # They shall be always compatible... they are a-a
                new.combinations *= 2
                assert(new is not None)
                lst = lst[:k] + [new] + lst[k+2:]
                break
        else:
            # No reduction done, exit
            break

    # Early failure, b-c b-x ==> Incompatible
    for k in range(len(lst)-1):
        if lst[k].is_aa_wagon() or lst[k+1].is_aa_wagon():
            continue
        if lst[k].left == lst[k+1].left:
            return 0
        if lst[k].right == lst[k+1].right:
            return 0

    # Start to form clusters until only 1 element left
    has_reduced = True
    while len(lst) > 1 and has_reduced:
        has_reduced = False
        for k in range(len(lst)-1):
            # Try to cluster the element k
            if lst[k+1].left != lst[k].right:
                continue

            new = lst[k].reduce(lst[k+1])
            if new is None:
                # This really does not form a cluster...
                continue
            else:
                lst = lst[:k] + [new] + lst[k+2:]
                has_reduced = True
                break

    # Ok, we have a big train... that we can shift
    n = 0
    for p in permutations(lst):
        m = 1
        for x in p:
            m *= x.combinations % MODULO
        n += m
    return n % MODULO


def solve(fd):
    """
    Solve all the cases from fd
    """

    t = int(fd.readline().strip())
    for k in range(t):
        # Read the number of wagons
        n = int(fd.readline().strip())
        lst = fd.readline().strip().split()
        assert(len(lst) == n)
        res = solution(lst)
        print("Case #{}: {}".format(k+1, res))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        infile = sys.stdin
    else:
        infile = open(sys.argv[1], 'r')

    solve(infile)

    infile.close()