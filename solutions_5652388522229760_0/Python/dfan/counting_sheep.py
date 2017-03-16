#!/usr/bin/python

import sys

def solve(N, i):
    """Main solution"""
    seen = set()
    digits_seen = [False for _ in xrange(10)]
    n = N
    while n not in seen:
        seen.add(n)
        for d in digits(n):
            digits_seen[d] = True
        if all(digits_seen):
            output_case(i, str(n))
            return
        n += N
    output_case(i, "INSOMNIA")

def digits(n):
    """ Gets digits of n, returned in reverse order"""
    n = abs(n)
    d = []
    while n > 0:
        d.append( n % 10 )
        n /= 10
    return d

def read_int_list(line, separator=" "):
    return map(int, line.strip().split(separator))

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "input.txt" if no command line
filename = "A-small-attempt0.in"
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        # N
        N, = read_int_list(input_file.readline())
        solve(N, i)