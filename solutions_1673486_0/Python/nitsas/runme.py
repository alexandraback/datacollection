#!/usr/bin/env python3.2
"""
Password Problem problem
for Google Code Jam 2012
Round 1A

Link to problem description:
http://code.google.com/codejam/contest/1645485/dashboard#s=p0

author: 
Christos Nitsas
(chrisn654)

language:
Python 3.2.1

date:
April, 2012

usage:
$ python3.2 runme.py sample.in
or
$ runme.py sample.in
(where sample.in is the input file and $ the prompt)
"""


import sys
# non-standard modules:
from helpful import read_int, read_list_of_int, read_list_of_float


def expected_num_keystrokes(a, b, p):
    prob_first_k_correct = [1.0]
    for i in range(a):
        prob_first_k_correct.append(prob_first_k_correct[-1] * p[i])
    expected_per_strategy = []
    expected_per_strategy.append(expected_keep_typing(a, b, prob_first_k_correct))
    expected_per_strategy.append(expected_press_enter(a, b, prob_first_k_correct))
    n = 1
    while 2 * n < a + 1:
        expected_per_strategy.append(expected_delete_n(a, b, prob_first_k_correct, n))
        n += 1
    return min(expected_per_strategy)


def expected_keep_typing(a, b, prob_first_k_correct):
    expected_keystrokes = prob_first_k_correct[a] * (b - a + 1)
    expected_keystrokes += (1 - prob_first_k_correct[a]) * (2 * b - a + 2)
    return expected_keystrokes


def expected_press_enter(a, b, p):
    return b + 2


def expected_delete_n(a, b, prob_first_k_correct, n):
    expected_keystrokes = prob_first_k_correct[a - n] * (2 * n + b - a + 1)
    expected_keystrokes += (1 - prob_first_k_correct[a - n]) * (2 * n + 2 * b - a + 2)
    return expected_keystrokes


def main(filename=None):
    if filename is None:
        if len(sys.argv) == 2:
            filename = sys.argv[1]
        else:
            print("Usage: runme.py input_file")
            return 1
    with open(filename, "r") as f:
        num_test_cases = read_int(f)
        for i in range(1, num_test_cases + 1):
            A, B = read_list_of_int(f)
            P = read_list_of_float(f)
            print("Case #{0}: {1}".format(i, expected_num_keystrokes(A, B, P)))
    return 0


if __name__ == "__main__":
    status = main()
    sys.exit(status)

