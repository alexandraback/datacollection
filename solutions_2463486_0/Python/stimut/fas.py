#!/usr/bin/env python

import sys
from math import ceil, floor, sqrt

def memoize(func):
    cache = {}
    @wraps(func)
    def wrap(*args):
        if args not in cache:
            cache[args] = func(*args)
        return cache[args]
    return wrap


def read_ints():
    return [int(x) for x in sys.stdin.readline().split()]

def is_palindrome(word):
    length = len(word)
    if length == 1:
        return True

    for ii in range(length//2):
        if word[ii] != word[-1-ii]:
            return False

    return True

T = int(input())

for case in range(T):
    print("Case #", case+1, ": ", sep='', end='')

    A, B = read_ints()

    start = ceil(sqrt(A))
    end = floor(sqrt(B))

    count = 0
    for num in range(start, end+1):
        if not is_palindrome(str(num)):
            continue
        if is_palindrome(str(num*num)):
            count += 1

    print(count)

