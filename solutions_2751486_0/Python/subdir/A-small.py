#!/usr/bin/python3

import sys
from itertools import groupby

def consonant(letter):
    return letter not in {'a', 'e', 'i', 'o', 'u'}

def max_consequtive_consonants(name):
    res = 0
    for conson, letters in groupby(name, consonant):
        if conson:
            s = sum(1 for letter in letters)
            if s > res:
                res = s
    return res

def solve(name, n):
    L = len(name)
    res = 0
    for left in range(L - n + 1):
        for right in range(left + n, L + 1):
            if max_consequtive_consonants(name[left:right]) >= n:
                res += 1
    return res

def main():
    T = int(next(sys.stdin))
    for t in range(T):
        name, n = next(sys.stdin).split()
        n = int(n)
        print("Case #{}: {}".format(t+1, solve(name, n)))

main()

