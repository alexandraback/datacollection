#!/usr/bin/env python3

# Google Code Jam
# Qualification Round 2016
# Problem D. Fractiles
# Solution in Python by Smithers

def tileindex(k, c, s, i):
    n = 1
    for j in range(c):
        n += (i + j * s if i + j * s < k else 0) * (k ** j)
    return n

def solve(k, c, s):
    if s * c < k:
        return 'IMPOSSIBLE',
    
    return [tileindex(k, c, s, i) for i in range(s)]

for i in range(int(input())):
    k, c, s = (int(x) for x in input().split())
    print('Case #{}:'.format(i + 1), *solve(k, c, s))
