#!/usr/bin/env python
# Python 3

import platform
assert platform.python_version_tuple()[0] == '3'


def solution(n, grid):
    heights = {}

    for li in grid:
        for n in li:
            if n in heights:
                heights[n] += 1
            else:
                heights[n] = 1

    odds = list(filter(lambda item: item[1] % 2.0 == 1, heights.items()))
    missing_unsorted = [key for (key, value) in odds]
    missing_sorted = sorted(missing_unsorted)
    return " ".join(map(str, missing_sorted))

# Taken from https://code.google.com/codejam/tutorials.html
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# Customize the lines in the for loop to suit the input format
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    n = int(input())
    grid = []
    for throwaway in range(2*n - 1):
        grid.append([int(s) for s in input().split(" ")])

    print("Case #{}: {}".format(i, solution(n, grid)))
