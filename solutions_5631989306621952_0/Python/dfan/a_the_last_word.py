#!/usr/bin/python

import sys

def solve(S, i):
    """Main solution"""
    answer = S[0]
    for letter in S[1:]:
        # New letter smaller, put at end
        if answer[0] > letter:
            answer += letter
        else:
            answer = letter + answer
    return answer

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
        # pancake stack
        S = input_file.readline().strip()
        result = solve(S, i)
        output_case(i, result)