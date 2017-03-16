#!/usr/bin/python
'''
Google code jam 2013
Round 1A
Manage your Energy

By Tyrus Tenneson
2013-04-26
'''

import sys
import collections
import math
import decimal
import re

'''
Solution
'''
def bf_sol(e, e0, r, values):
    '''
    Some brute force, inefficient but should be fine for small
    '''
    # base case, one thing left
    if len(values) == 1:
        return e*values[0]
    max_gain = 0
    for spend in range(e+1):
        this_gain = spend*values[0] + bf_sol(min(e-spend+r,e0), e0, r, values[1:])
        if this_gain > max_gain:
            max_gain = this_gain
    return max_gain

def eval_case(case):
    '''
    Returns solution to case
    '''
    e0, r, n = case[0]
    values = case[1]
    return bf_sol(e0, e0, r, values)
    
'''
I/O
'''
def chunk_list(lst, size):
    return_me = []
    chunk = []
    for element in lst:
        if len(chunk) >= size:
            return_me.append(tuple(chunk))
            chunk = [element]
        else:
            chunk.append(element)
    return_me.append(tuple(chunk))
    return tuple(return_me)

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
        lines = (process_line(line) for line in input.readlines())
        cases = chunk_list(lines, 2)
    return cases

def solve():
    cases = map(eval_case, process_input())
    for idx, val in enumerate(cases):
        write_string = "Case #%i: %s\n" % (idx+1, val)
        print write_string,

if __name__ == "__main__":
    solve()