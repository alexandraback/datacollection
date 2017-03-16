#!/usr/bin/python
'''
Google code jam 2013
Round 1C
Consonants

By Tyrus Tenneson
2013-05-11
'''

import sys
import collections
import math
import re

'''
Solution
'''
VOWLES = ['a','e','i','o','u']

def eval_case(case):
    '''
    Returns solution to case
    n^2 solution
    '''
    word, size = case
    score = 0
    for i in range(len(word)):
        for j in range(i+1, len(word)+1):
            substring = word[i:j]
            count = 0
            for char in substring:
                if char not in VOWLES:
                    count += 1
                else:
                    count = 0
                if count >= size:
                    score += 1
                    break
    return score
'''
I/O
'''
def chunks(l, n):
    '''
    Yield successive n-sized chunks from l.
    http://stackoverflow.com/a/312464
    '''
    for i in xrange(0, len(l), n):
        yield l[i:i+n]

def process_case_lines(case_lines):
    if type(case_lines) == tuple:
        return_me = []
        for line in case_lines:
            line = line.rstrip().split(' ')
            return_me.append(tuple(str(line[0]), int(line[1])))
        return tuple(return_me)
    else:
        line = case_lines.rstrip().split(' ')
        return (str(line[0]), int(line[1]))

def process_input():
    '''
    Returns list of strings, each string is a case.
    '''
    with sys.stdin as input:
        # first line is number of cases
        num_cases = int(input.readline().rstrip())
        lines = tuple(input.readlines())
        if len(lines)/num_cases != 1:
            lines = chunks(lines, len(lines)/num_cases)
        cases = tuple(map(process_case_lines, lines))
    return cases

def solve():
    cases = map(eval_case, process_input())
    for idx, val in enumerate(cases):
        write_string = "Case #%i: %s\n" % (idx+1, val)
        print write_string,

if __name__ == "__main__":
    solve()