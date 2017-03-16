#!/usr/bin/env python
import sys


def solve_case(n):
    seen = set()
    full_set = set([str(i) for i in xrange(10)])
    no_change_limit = 500
    no_change_count = 0
    multiplier = 1

    while seen != full_set and no_change_count < no_change_limit:
        seen_set_length = len(seen)
        seen = seen.union(set([i for i in str(multiplier * n)]))
        if seen_set_length == len(seen):
            no_change_count += 1
        else:
            no_change_count = 0
        multiplier += 1
    if seen == full_set:
        return (multiplier - 1) * n
    return None


def read_and_save():
    case_count = int(sys.stdin.readline())
    for i in xrange(1, case_count+1):
        n = int(sys.stdin.readline())
        solution = solve_case(n)
        print 'Case #{}: {}'.format(i, solution or 'INSOMNIA')


if __name__ == '__main__':
    read_and_save()
