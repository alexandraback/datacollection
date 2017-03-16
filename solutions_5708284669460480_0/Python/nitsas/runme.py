#!/usr/bin/env python3
"""
Typewriter Monkey problem
for Google Code Jam 2015
Round 1C

Link to problem description:
https://code.google.com/codejam/contest/4244486/dashboard#s=p1

Author: 
  Chris Nitsas
  (nitsas)

Language:
  Python 3(.4)

Date:
  May, 2015

Usage:
  python3 runme.py input_file
"""


import sys
import argparse
from collections import Counter
from math import ceil
# modules I've written:
from helpful import read_int, read_list_of_int, read_str


_program_description = \
'''TEMPLATE PROGRAM DESCRIPTION'''


_input_file_description = \
'''TEMPLATE INPUT FILE DESCRIPTION'''


class TestCase:
    pass


def parse_args():
    """
    Parse the command line arguments and return them in a namespace.
    """
    parser = argparse.ArgumentParser(description=_program_description)
    parser.add_argument('input_file', help=_input_file_description)
    #parser.add_argument('-v', '--verbose', action='store_true', 
    #                    default=False, help='show progress')
    args = parser.parse_args()
    return args


def read_test_case(file_):
    """Read and return a single test case."""
    tc = TestCase()
    tc.K, tc.L, tc.S = read_list_of_int(file_)
    tc.letter_counter = Counter(read_str(file_))
    tc.target_word = read_str(file_)
    return tc


def output_of_test_case(tc):
    """Return the output of a single test case as a string."""
    if tc.L > tc.S:
        return str(0.0)
    if target_word_is_impossible_with_given_keys(tc):
        return str(0.0)
    tc.tightest_overlap = compute_tightest_overlap(tc.target_word)
    tc.max_num_occurrences = compute_max_num_occurrences(tc)
    expected_num_occurrences = compute_expected_num_occurrences(tc)
    return str(tc.max_num_occurrences - expected_num_occurrences)


def target_word_is_impossible_with_given_keys(tc):
    for letter in tc.target_word:
        if tc.letter_counter[letter] == 0:
            return True
    return False


def compute_tightest_overlap(word):
    for i in range(1, len(word)):
        if word[i:] == word[:-i]:
            return i
    return len(word)


def compute_max_num_occurrences(tc):
    return ceil( (tc.S - tc.L + 1) / tc.tightest_overlap )


#def compute_expected_num_occurrences(tc):
#    match_probability = compute_match_probability(tc)
#    return tc.max_num_occurrences * match_probability


def compute_expected_num_occurrences(tc):
    match_probability = compute_match_probability(tc)
    return (tc.S - tc.L + 1) * match_probability


def compute_match_probability(tc):
    match_probability = 1
    for letter in tc.target_word:
        match_probability *= tc.letter_counter[letter] / tc.K
    return match_probability


def main(filename):
    with open(filename, 'r', encoding='utf-8') as f:
        T = read_int(f)
        test_cases = [read_test_case(f) for i in range(T)]
    for i, tc in enumerate(test_cases, start=1):
        print("Case #{}: ".format(i) + output_of_test_case(tc))
    return 0


if __name__ == "__main__":
    status = main(parse_args().input_file)
    sys.exit(status)
