#!/usr/bin/python
#flake8: noqa

import sys
from collections import defaultdict

def solve(topics, i):
    """Main solution"""
    first_word = defaultdict(int)
    second_word = defaultdict(int)

    count = 0

    for topic in topics:
        first_word[topic[0]] += 1
        second_word[topic[1]] += 1

    for index, topic in enumerate(topics):
        if first_word[topic[0]] >= 2 and second_word[topic[1]] >= 2:
            first_word[topic[0]] -= 1
            second_word[topic[1]] -= 1
            count += 1

    return str(count)

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "A-large.in" if no command line args
filename = "A-large.in"
if len(sys.argv) >= 2:
    filename = sys.argv[1]
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        # Number of topics
        N = int(input_file.readline())
        topics = []
        for j in xrange(N):
            topics.append(input_file.readline().strip().split())
        result = solve(topics, i)
        output_case(i, result)
