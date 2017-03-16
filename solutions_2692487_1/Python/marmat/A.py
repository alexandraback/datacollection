#!/usr/bin/env python

import math
import sys

# Global variables
output_file = None
current_case = 1
DEBUG = True


# The main method which will receive a parsed input file
def jam(lines):
    # Fixed number of lines
    for i in range(1, len(lines), 2):
        A, N = map(int, lines[i].split())
        motes = map(int, lines[i+1].split())
        motes.sort()
        print_solution(str(min_actions(A, motes[:])))


# Case-specific program
def min_actions(own, motes):
    # Add as many as possible
    while len(motes) > 0 and motes[0] < own:
        own += motes.pop(0)

    if len(motes) == 0:
        return 0

    print own,motes

    # Option A: delete all remaining motes
    # actions == len(motes)

    # Option B: add something and then search further
    additions = 0
    if (own == 1):
        # our own mote can't grow!!
        return len(motes)

    while (motes[0] >= own):
        additions += 1
        own += own - 1

    return min(len(motes), additions + min_actions(own, motes[:]))


# Boilerplate: method for printing a result
def print_solution(solution):
    global current_case
    global output_file
    result = "Case #%d: %s" % (current_case, solution)
    current_case += 1
    output_file.write(result + "\n")
    if DEBUG:
        print result


# Main entry point, parses input and prepares output file
if __name__ == "__main__":
    lines = []
    filename = "%s-%s-%s" % (sys.argv[1], sys.argv[2], sys.argv[3])
    input_file = file(filename + ".in")
    output_file = file(filename + ".out", 'w')

    for line in input_file:
        lines.append(line.rstrip('\n'))

    jam(lines)
