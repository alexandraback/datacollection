#!/usr/bin/python

import sys
from collections import defaultdict

# memoized
length_to_repeat_cache = {}
def length_to_repeat(bff, i, seen = []):
    if i in seen:
        length_to_repeat_cache[i] = 0
    else:
        length_to_repeat_cache[i] = length_to_repeat(bff, bff[i], seen + [i]) + 1
    return length_to_repeat_cache[i]

def is_in_2_cycle(bff, i):
    return length_to_repeat(bff, i) == 2

# memoized
ending_2_cycle_cache = defaultdict(lambda: None)
def ending_2_cycle(bff, i, seen = []):
    if i in seen:
        ending_2_cycle_cache[i] = None
    elif length_to_repeat(bff, i) == 2:
        cycle_name =(i, bff[i])
        ending_2_cycle_cache[i] = cycle_name
    else:
        ending_2_cycle_cache[i] = ending_2_cycle(bff, bff[i], seen + [i])
    return ending_2_cycle_cache[i]

def max_2_cycles(bff):
    pass

def solve(F, N, i):
    """Main solution"""
    # pull out students when we have seen them once
    unchecked = set(range(1, N+1))
    # i.e. sources
    friendless = set(xrange(1, N+1))

    # construct graph
    bff = {}
    for i in xrange(N):
        bff[i + 1] = F[i]
        if F[i] in friendless:
            friendless.remove(F[i])

    # find two-cycles
    two_cycle_size = defaultdict(int)
    # for i in xrange(1, N+1):
    #     if is_in_2_cycle(bff, i):
    #         two_cycle_size[(i, bff[i])] = []

    # calculate the "size" of a 2-cycle, defined as the sum of lengths of the
    # two largest incoming paths, minus 2 (double counting 2-cycle)
    for i in friendless:
        cycle_name = ending_2_cycle(bff, i)
        if cycle_name:
            two_cycle_size[cycle_name] = \
                max(two_cycle_size[cycle_name], length_to_repeat(bff, i))

    # down to cannonical cycle naming
    total_two_cycle_size = defaultdict(lambda: 2)
    for cycle_name, length in two_cycle_size.iteritems():
        total_two_cycle_size[tuple(sorted(cycle_name))] += length - 2

    two_cycle_length = 0
    for cycle_name, length in total_two_cycle_size.iteritems():
        two_cycle_length += length
    # print two_cycle_length

    max_cycle = 0
    while len(unchecked) != 0:
        start_student = unchecked.pop()
        cur_student = start_student
        cur_cycle = 0
        seen = {}
        while True:
            # Track where we saw this student
            seen[cur_student] = cur_cycle
            cur_student = bff[cur_student]
            cur_cycle += 1

            # We never need to start at this student again
            if cur_student in unchecked:
                unchecked.remove(cur_student)

            # If we've seen the next student, subtract where this happened go get the cycle
            if cur_student in seen:
                cur_cycle -= seen[cur_student]
                break
        max_cycle = max(max_cycle, cur_cycle)
    # print max_cycle
    return max(max_cycle, two_cycle_length)

def read_int_list(line, separator=" "):
    return map(int, line.strip().split(separator))
    return map(int, line.strip().split(separator))

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
        N, = read_int_list(input_file.readline())
        F = read_int_list(input_file.readline())
        result = solve(F, N, i)
        output_case(i, result)