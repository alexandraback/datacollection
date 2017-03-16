#!/usr/bin/python

import sys

def solve(pancakes, i):
    """Main solution"""
    pancakes += "+"
    return pancakes.count("-+") + pancakes.count("+-")

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "input.txt" if no command line
filename = "B-large.in"
if len(sys.argv) >= 2:
    filename = sys.argv[1]
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        # pancake stack
        pancakes = input_file.readline().strip()
        result = solve(pancakes, i)
        output_case(i, result)