#!/usr/bin/python

import sys

def solve(K, C, S, i):
    """Main solution"""
    if C*S < K:
        return "IMPOSSIBLE"
    indices = [to_check(K, C, i) + 1 for i in xrange(0, K, C)]
    return " ".join(map(str, indices))

def to_check(K, C, start):
    """
    Gives the index in the final fractile to check in order to get information
    on indices `start` to `start+C-1`
    """
    index_to_check = 0
    for i in xrange(start, min(start + C, K)):
        index_to_check *= K
        index_to_check += i
    # checking this index will given information on the C tiles from start
    return index_to_check

def read_int_list(line, separator=" "):
    return map(int, line.strip().split(separator))

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "D-large.in" if no command line
filename = "D-large.in"
if len(sys.argv) >= 2:
    filename = sys.argv[1]
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        # pancake stack
        K, C, S = read_int_list(input_file.readline())
        result = solve(K, C, S, i)
        output_case(i, result)