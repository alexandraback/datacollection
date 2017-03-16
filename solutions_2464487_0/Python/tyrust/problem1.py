#!/usr/bin/python
'''
Google code jam 2013
Round 1A
Bullseye

By Tyrus Tenneson
2013-04-26
'''

import sys
import collections
import math
import re

'''
Solution
'''
def eval_case(case):
    '''
    Returns solution to case
    '''
    r, t = case
    ring_count = 0
    while (2*r + 1) <= t:
        ring_count += 1
        t -= (2*r + 1)
        r += 2
    return ring_count

'''
I/O
'''
def process_line(line):
    return tuple(map(int, line.rstrip().split(' ')))

def process_input():
    '''
    Returns list of strings, each string is a case.
    '''
    #with open(file_path, 'r') as input:
    with sys.stdin as input:
        # first line is number of cases
        num_cases = int(input.readline().rstrip())
        cases = (process_line(line) for line in input.readlines())
    return cases

def solve():
    cases = map(eval_case, process_input())
    for idx, val in enumerate(cases):
        write_string = "Case #%i: %s\n" % (idx+1, val)
        print write_string,

if __name__ == "__main__":
    solve()