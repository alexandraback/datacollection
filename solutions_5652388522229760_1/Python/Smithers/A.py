#!/usr/bin/env python3

# Google Code Jam
# Qualification Round 2016
# Problem A. Counting Sheep
# Solution in Python by Smithers

def solve(n):
    if n == 0:
        return 'INSOMNIA'
    
    seen = [False] * 10
    x = 0
    while not all(seen):
        x += n
        for c in str(x):
            seen[int(c)] = True
    return x

for c in range(int(input())):
    n = int(input())
    print('Case #{}: {}'.format(c + 1, solve(n)))
