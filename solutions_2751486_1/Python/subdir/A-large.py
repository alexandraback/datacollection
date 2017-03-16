#!/usr/bin/python3

import sys
from itertools import groupby
from collections import deque

def consonant(letter):
    return letter not in {'a', 'e', 'i', 'o', 'u'}

def solve(name, n):
    L = len(name)
    name0 = deque()
    i = 0
    for conson, letters in groupby(name, consonant):
        s = sum(1 for letter in letters)
        if conson and s >= n:
            name0.append((i, s))
        i += s

    res = 0
    if name0:
        pos, size = name0.popleft()
        for left in range(L):
            if left > pos:
                pos += 1
                size -= 1
                if size < n:
                    if name0:
                        pos, size = name0.popleft()
                    else:
                        break
            res += L - (pos + n) + 1
    return res

def main():
    T = int(next(sys.stdin))
    for t in range(T):
        name, n = next(sys.stdin).split()
        n = int(n)
        print("Case #{}: {}".format(t+1, solve(name, n)))

main()

