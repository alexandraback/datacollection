#!/usr/bin/env python


from __future__ import print_function


import argparse
import sys
from itertools import combinations


def solve(numbers):
    test = {}
    for length in xrange(1, len(numbers)):
        for combination in combinations(numbers, length):
            candidate = sum(combination)
            if candidate in test:
                return combination, test[candidate]
            else:
                test[candidate] = combination



def main(args):
    tests = next(args.input).strip()
    for index, line in enumerate(args.input, 1):
        print('Case #{}:'.format(index))
        line = map(int, line.strip().split())
        numbers  = sorted(line[1:])
        solution = solve(numbers)
        if solution is not None:
            print(' '.join(map(str, solution[0])))
            print(' '.join(map(str, solution[1])))
        else:
            print("Impossible")


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input', type=argparse.FileType('r'), default=sys.stdin)
    main(parser.parse_args())
