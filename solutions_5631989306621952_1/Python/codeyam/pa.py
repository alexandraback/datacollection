#!/usr/bin/env python
# Python 3

import platform
assert platform.python_version_tuple()[0] == '3'


def solution(s):
    letters = list(s)
    last = [letters[0]]

    for l in letters[1:]:
        if l < last[0]:
            # print("Appending " + l + " to " + "".join(last))
            last.append(l)
        else:
            # print("Prepending " + l + " to " + "".join(last))
            last.insert(0, l)

    return "".join(last)

# Taken from https://code.google.com/codejam/tutorials.html
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# Customize the lines in the for loop to suit the input format
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    s = input()
    print("Case #{}: {}".format(i, solution(s)))
