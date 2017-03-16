#!/usr/bin/env python3.3
"""
Consonants problem
for Google Code Jam 2013
Round 1C

Link to problem description:
https://code.google.com/codejam/contest/2437488/dashboard#s=p0

author: 
Christos Nitsas
(chrisn654)

language:
Python 3.2.3

date:
May, 2012

usage:
$ python3.2 runme.py sample.in
or
$ runme.py sample.in
(where sample.in is the input file and $ the prompt)
"""


import sys
import re
# non-standard modules:
from helpful import read_int, read_list_of_str


def substrings(name):
    for start in range(len(name)):
        for end in range(start + 1, len(name) + 1):
            yield name[start:end]


def compute_n_value(name, n):
    n_value = 0
    pattern = re.compile('[^aeiou]{{{0}}}'.format(n))
    for subname in substrings(name):
        if pattern.search(subname):
            n_value += 1
    return n_value


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
            name, num = read_list_of_str(f)
            n = int(num)
            print("Case #{0}:".format(i), end=" ")
            print(compute_n_value(name, n))
    return 0


if __name__ == "__main__":
    status = main()
    sys.exit(status)

