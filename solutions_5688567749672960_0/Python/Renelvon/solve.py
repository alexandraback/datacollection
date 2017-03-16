#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        t = int(next(f_in))
        for case in range(t):
            n = int(next(f_in))
            smallest = solve_instance(n)
            smallest = solve_instance_dynamic(n)
            print("Case #%d: %d" % (case + 1, smallest))


def solve_instance(n):
    start, count = 1, 1
    while start < n:
        if start + 1 < flip(start) <= n:
            start = flip(start)
        else:
            start += 1
        count += 1
    return count


def solve_instance_dynamic(n):
    dyn = list(range(n + 1))
    for i in range(12, n + 1):
        dyn[i] = min(dyn[i], dyn[i - 1] + 1)
        fi = flip(i)
        if fi > i and fi <= n:
            dyn[fi] = min(dyn[fi], dyn[i] + 1)
    return dyn[n]


def flip(number):
    return int(("".join(reversed(str(number))).lstrip("0")))


if __name__ == '__main__':
    main()
