#!/usr/bin/env python

import math
import sys

# Global variables
output_file = None
current_case = 1
DEBUG = True


# The main method which will receive a parsed input file
def jam(lines):
    for i in range(1, len(lines), 1):
        (name, n) = lines[i].split()
        print_solution(nval(name, int(n)))


# Case-specific program
def nval(name, n):
    last = -1
    val = 0
    for i in range(len(name) - n + 1):
        if consonant_free(name[i:i+n]):
            val += (i - last) * (len(name) - (i + n - 1))
            last = i

    return str(val)


def consonant_free(name):
    seen = {}
    for char in name:
        seen[char] = True

    for con in ['a', 'e', 'i', 'o', 'u']:
        if con in seen:
            return False

    return True

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
