#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        testcases = int(next(f_in))
        for i in range(testcases):
            x, r, c = tuple(int(num) for num in next(f_in).split())
            output = "GABRIEL" if is_feasible(x, r, c) else "RICHARD"
            print("Case #%d: %s" % (i + 1, output))


def is_feasible(x, r, c):
    if any((
        x >= 7,
        (r * c) % x != 0,
        x >= 3 and (r <= 1 or c <= 1),
        x == 4 and (r <= 2 or c <= 2)
    )):
        return False
    return True


if __name__ == '__main__':
    main()
