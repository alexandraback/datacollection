#!/bin/python3

def match(regex, number):
    number = str(number).zfill(len(regex))
    if len(regex) != len(number):
        return False
    for i, r in enumerate(regex):
        if r == '?':
            continue
        elif r != number[i]:
            return False
    return True

def min_number(regex):
    return int(''.join(['0' if c == '?' else c for c in regex]))
def max_number(regex):
    return int(''.join(['9' if c == '?' else c for c in regex]))

num_test_cases = int(input())
for case in range(1,num_test_cases+1):
    scoreboard = input().rstrip().split()
    min_difference = 99999999999999
    min_leftscore = 0
    min_rightscore = 1
    for left in range(min_number(scoreboard[0]), max_number(scoreboard[0])+1):
        if not match(scoreboard[0], left):
            continue
        for right in range(min_number(scoreboard[1]), max_number(scoreboard[1])+1):
            if not match(scoreboard[1], right):
                continue
            if abs(left - right) < min_difference:
                min_difference = abs(left - right)
                min_leftscore = left
                min_rightscore = right
    print("Case #{}: {} {}".format(case, str(min_leftscore).zfill(len(scoreboard[0])), str(min_rightscore).zfill(len(scoreboard[0]))))
