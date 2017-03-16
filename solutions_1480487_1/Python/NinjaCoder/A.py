#!/usr/bin/python

import sys

def solve(case):
    N = int(case[0])
    scores = map(int, case[1:])
    X = sum(scores)
    already_there = [score for score in scores if score >= 2 * X / float(N)]
    min_points = (2 * X - sum(already_there)) / float(N - len(already_there))
    return [100 * max(min_points - score, 0) / float(X) for score in scores]

input = [line.strip().split() for line in sys.stdin]
for index in range(1, int(input[0][0]) + 1):
    print 'Case #%d:' % index,
    for element in solve(input[index]):
        print '%.6f' % element,
    print
