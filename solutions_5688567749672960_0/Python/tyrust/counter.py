#!/usr/bin/python
'''
Google code jam 2015
Round 1B
Counter Culture

By Tyrus Tenneson
2015-05-02
'''

import sys

'''
Solution
'''
def reverse(n):
    return int(str(n)[::-1])

def dfs(): pass

def eval_case(case):
    '''
    Returns solution to case
    '''
    nums = set([1])
    i = 1
    while True:
        if i == case:
            break
        r, r1 = reverse(i), reverse(i+1)
        if (r > r1 or r1>case) and r<=case:
            i = max(i+1, reverse(i))
        else:
            i += 1
        nums.add(i)
    #print sorted(nums)
    return len(nums)

'''
I/O
'''
def process_input():
    '''
    Reads stdin, returns tuple of tuples (s_max, (s_1, ...)).
    '''
    with sys.stdin as input:
        num_cases = int(input.readline().rstrip())
        cases = []
        for line in input.readlines():
            digit = int(line.strip())
            cases.append(digit)
        assert num_cases == len(cases)
    return cases

def solve():
    cases = map(eval_case, process_input())
    for idx, val in enumerate(cases):
        write_string = "Case #%i: %s\n" % (idx+1, val)
        print write_string,

if __name__ == "__main__":
    solve()
