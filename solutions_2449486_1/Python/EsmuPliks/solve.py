#!/usr/bin/env python2
import sys

def __read_ints(iterable):
    line = next(iterable)
    return [int(i) for i in line.split()]


def is_valid(lawn):
    height = len(lawn)
    width = len(lawn[0])
    col_sets = [frozenset(lawn[r][col_i] for r in range(height)) for col_i in range(width)]
    row_sets = [frozenset(r) for r in lawn]

    for row_i in range(height):
        for col_i in range(width):
            curr = lawn[row_i][col_i]
            if not (curr >= max(col_sets[col_i]) or curr >= max(row_sets[row_i])):
                return "NO"

    return "YES"


def main():
    num_cases = int(next(sys.stdin))
    for i in range(num_cases):
        height, width = __read_ints(sys.stdin)
        lawn = [__read_ints(sys.stdin) for _ in range(height)]
        print "Case #%d: %s" % (i+1, is_valid(lawn))


if __name__ == '__main__':
    main()
