#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        testcases = int(next(f_in))
        for i in range(testcases):
            diners = int(next(f_in))
            pancakes = tuple(int(num) for num in next(f_in).split())
            output = solve_instance(diners, pancakes)
            print("Case #%d: %d" % (i + 1, output))


def solve_instance(_, pancakes):
    biggest_stack = max(pancakes)
    return min(
        eating_rounds + count_serving_rounds(pancakes, eating_rounds)
        for eating_rounds in range(biggest_stack, 0, -1)
    )


def count_serving_rounds(stacks, limit_stack):
    return sum((stack - 1) // limit_stack for stack in stacks)


if __name__ == '__main__':
    main()
