#!/usr/bin/env python3
import itertools
import collections
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        testcases = int(next(f_in))
        for i in range(testcases):
            N = int(next(f_in))
            topics = [next(f_in).rstrip().split() for i in range(N)]
            output = solve_instance(N, topics)
            print("Case #%d: %d" % (i + 1, output))


def solve_instance(n, topics):
    first = set(w[0] for w in topics)
    second = set(w[1] for w in topics)
    maxx = max(len(first), len(second))
    for origincount in range(maxx, n + 1):
        for originals in itertools.combinations(topics, origincount):
            first = set(w[0] for w in originals)
            second = set(w[1] for w in originals)
            if all(w[0] in first and w[1] in second for w in topics):
                return n - origincount
    return 0

if __name__ == '__main__':
    main()
