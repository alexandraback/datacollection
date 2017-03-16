#!/usr/bin/python

import sys
from collections import defaultdict
# from copy import copy, deepcopy

# def try_grid(grid, remaining, index):
#     # we have filled an index x index portion of the grid so far, so the
#     # indexth row and column are unused
#     valid = False
#     row_start = grid[index][0]
#     for lst in remaining[row_start]:
#         # check that adding this as a row is valid
#         if all([lst[i] == grid[index][i] for i in xrange(index)]):
#             next_grid = deepcopy(grid)
#             next_remaining = deepcopy(remaining)
#             if try_grid(next_grid, next_remaining, index + 1)

def solve(height_lists, N, i):
    """Main solution"""
    # Sort elements with odd parity
    occurrances = defaultdict(int)
    for lst in height_lists:
        for x in lst:
            occurrances[x] += 1

    missing = []
    for x, mult in occurrances.iteritems():
        if mult % 2 != 0:
            missing.append(x)

    missing.sort()
    return " ".join(map(str,missing))

    # # The smallest integer should be present in one of these lists.
    # # The problem doesn't tell us that this integer is necessarily 1
    # smallest = min(map(min, height_lists))

    # # Fill in grid and row/col_used. Do linear search over row/col_used
    # # to find the missing row, and grab values from grid
    # grid = [[None for _ in xrange(N)] for _ in xrange(N)]

    # row_used = [False for _ in xrange(N)]
    # col_used = [False for _ in xrange(N)]

    # # The shortest person is unique. Interchanging rows and columns does not
    # # matter since the problem is identical under transposition
    # grid[0] = 

    # for r in grid:
    #     print r
    # print row_used
    # print col_used
    # print height_lists, smallest

def read_int_list(line, separator=" "):
    return map(int, line.strip().split(separator))

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "input.txt" if no command line
filename = "A-large.in"
if len(sys.argv) >= 2:
    filename = sys.argv[1]
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        N, = read_int_list(input_file.readline())
        height_lists = []
        for j in xrange(2 * N - 1):
            height_lists.append(read_int_list(input_file.readline()))
        result = solve(height_lists, N, i)
        output_case(i, result)