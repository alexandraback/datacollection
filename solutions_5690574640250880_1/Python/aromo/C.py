#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
from numpy import *

sys.setrecursionlimit(10000)

def input_words():
    line = IN.readline()
    return line.strip().split()

def input_ints():
    return map(int, input_words())

def input_floats():
    return map(float, input_words())

def format_sequence(s, formatter='%s'):
    return " ".join(map(lambda x: formatter % (x,), s))

def partitions(N, smallest_allowed=1, largest_allowed=None, max_items=None):
    """ partitions with decreasing numbers """
    if N == 0:
        yield []

    if largest_allowed is None:
        largest_allowed = N

    if max_items is None:
        max_items = N

    if max_items > 0:
        for smallest in range(smallest_allowed, min(N, largest_allowed) + 1)[::-1]:
            for p in partitions(N - smallest, smallest_allowed=smallest, largest_allowed=largest_allowed, max_items=max_items - 1):
                yield p + [smallest]


def ppartitions(N, smallest_allowed=1, largest_allowed=None, max_items=None):
    """ partitions which repeat the first (largest) entry """
    if largest_allowed is None:
        largest_allowed = N

    if max_items is None:
        max_items = N

    for first_item in range(smallest_allowed, 1 + min(N // 2, largest_allowed))[::-1]:
        for p in partitions(N - 2 * first_item, smallest_allowed=smallest_allowed, largest_allowed=first_item, max_items=max_items - 2):
            yield [first_item, first_item] + p


def free_partitions(R, C, F):
    for p in ppartitions(F, smallest_allowed=min(2, C), largest_allowed=C, max_items=R):
        yield p

def real(R, C, F):
    if F == 1:
        p = [1]

    elif R == 1:
        p = [F]

    else:
        try:
            p = free_partitions(R, C, F).next()
        except StopIteration:
#            print F, R, C
            return "Impossible"
            p = None
        
    solution = 'c' + '.' * (p[0] - 1) + '*' * (C - p[0])

    for r in p[1:]:
        solution += '\n' + '.' * r + '*' * (C - r)

    solution += ('\n' + '*' * C) * (R - len(p))

    return solution

def solve_one():
    """ XXX the real code comes here """
    R, C, M = input_ints()
    F = R * C - M
    return real(R, C, F)


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
#        _ = solve_one()
        print "Case #%d:\n" % (i+1,), solve_one()
        sys.stderr.write("CASE #%d DONE\n" % (i+1,))
        sys.stderr.flush()


#print real(5, 5, 3)

# print list(partitions(6))
# print list(partitions(6, largest_allowed=3))
# print list(partitions(6, largest_allowed=3, max_items=5))
# print '---'

# print list(ppartitions(6))
# print list(ppartitions(6, largest_allowed=3))
# print list(ppartitions(6, largest_allowed=3, max_items=5))

# R, C = 50, 50
# for i in range(R*C + 1):
#     try:
#         solution = free_partitions(R, C, i).next()
#     except StopIteration:
#         solution = None
#         print i, solution
