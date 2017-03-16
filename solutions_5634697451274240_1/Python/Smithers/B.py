#!/usr/bin/env python3

# Google Code Jam
# Qualification Round 2016
# Problem B. Revenge of the Pancakes
# Solution in Python by Smithers

def solve(s):
    return sum(1 if x != y else 0 for x, y in zip(s, s[1:] + '+'))

for c in range(int(input())):
    s = input()
    print('Case #{}: {}'.format(c + 1, solve(s)))
