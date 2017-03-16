#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Round 1 - Problem C -
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys
from collections import defaultdict

def check_solution(topics, solution, first, second):

    f = set()
    s = set()

    for i, (t1, t2) in enumerate(topics):
        if solution[i] == '1':
            f.add(t1)
            s.add(t2)

    if len(first - f) > 0:
        return False

    if len(second -s) > 0:
        return False
    return True

def solve(topics):

    first = set()
    second = set()

    n_topics = len(topics)

    max_l = 0
    for f, s in topics:
        first.add(f)
        second.add(s)

    for code in xrange(1,(2 ** len(topics))+1):
        solution = ("{0:0b}").format(code)
        while len(solution) < n_topics:
            solution = '0' + solution

        count_0 = sum([1 for x in solution if x == '0'])

        if count_0 > max_l:
            if check_solution(topics,solution,first,second):
                max_l = max(max_l, count_0)

    return max_l


input_path = sys.argv[1]

with open(input_path) as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        n_topics = int(input_file.readline().strip())
        topics = []
        for t in xrange(n_topics):
            topic = input_file.readline().strip().split()
            topics.append(topic)
        solution = solve(topics)
        print 'Case #{0}: {1}'.format(case, solution)
