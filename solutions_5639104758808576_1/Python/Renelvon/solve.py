#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        next(f_in)
        for i, input_line in enumerate(f_in):
            smax_str, audience_str = input_line.split()
            smax = int(smax_str)
            audience = tuple(int(num) for num in audience_str)
            output = solve_instance(smax, audience)
            print("Case #%d: %d" % (i + 1, output))


def solve_instance(_, audience):
    total_clappers, additional_friends = 0, 0
    for shyness, clappers in enumerate(audience):
        help_needed = max(0, shyness - total_clappers)
        additional_friends += help_needed
        total_clappers += help_needed + clappers
    return additional_friends


if __name__ == '__main__':
    main()
