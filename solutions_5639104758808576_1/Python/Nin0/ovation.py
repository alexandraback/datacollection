#!/usr/bin/python3

import sys

t = int(sys.stdin.readline())

def solve(s_max, s):
    standing = 0
    invited = 0
    for i in range(s_max + 1):
        if standing >= i:
            standing += s[i]
        else:
            invited += i - standing
            standing += s[i] + (i - standing)
    return invited

for i in range(1, t+1):
    s_max, s = sys.stdin.readline().split()
    s_max = int(s_max)
    s = [int(c) for c in s]
    friends = solve(s_max, s)
    print('Case #{0}: {1}'.format(i, friends))


