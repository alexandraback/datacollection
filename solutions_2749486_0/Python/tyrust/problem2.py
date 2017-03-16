#!/usr/bin/python
'''
Google code jam 2013
Round 1C
Pogo

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
def pair_change(dx, dy):
    def return_me(location, scale):
        return (location[0]+(dx*scale), location[1]+(dy*scale))
    return return_me

JUMP = {'N': pair_change(0,1),
        'E': pair_change(1,0),
        'S': pair_change(0,-1),
        'W': pair_change(-1,0)}

def get_attempt():
    attempts = {}
    for key, fn in JUMP.iteritems():
        attempts[fn((0,0), 1)] = key
    #c = 0
    while 1:
        #sys.stderr.write(str(c) + '\n')
        #sys.stderr.write(str(len(attempts)) + '\n')
        #c += 1
        new_attempts = {}
        for location, old_attempt in attempts.iteritems():
            for direction, fn in JUMP.iteritems():
                new_location = fn(location, len(old_attempt)+1)
                new_attempts[new_location] = old_attempt + direction
                yield (new_location, old_attempt + direction)
        attempts = new_attempts

def make_attempt(attempt, print_=False):
    location = (0,0)
    for idx, direction in enumerate(attempt):
        location = JUMP[direction](location, idx+1)
        if print_:
            print location
    return location

def brute_force(start, target):
    '''
    BFS
    '''
    for location, attempt in get_attempt():
        if location == target:
            make_attempt(attempt, False)
            return attempt        
count = 0
def eval_case(case):
    '''
    Returns solution to case
    '''
    target = case
    start = (0,0)
    return_me = brute_force(start, target)
    global count
    count += 1
    sys.stderr.write(str(count))
    return return_me
    
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
            return_me.append(tuple(map(int, line.rstrip().split(' '))))
        return tuple(return_me)
    else:
        return tuple(map(int, case_lines.rstrip().split(' ')))

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