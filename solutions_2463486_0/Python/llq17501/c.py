#!/usr/bin/env python
#-*- coding:utf-8 -*-

from itertools import product
import sys

get_ints = lambda f:map(int, next(f).strip().split(' '))

def is_palindromes(i):
    s = str(i)
    return all(s[j] == s[-1 - j] for j in range(len(s)/2))

def all_above(n):
    for i in range(n):
        for p in product(*[range(1 if j == 0 else 0, 10) for j in range(i+1)]):
            N1 = sum((p[j] if j < len(p) else p[2 * i - j]) * 10 ** j  for j in range(2 * i + 1))
            N2 = sum((p[j] if j < len(p) else p[2 * i + 1 - j]) * 10 ** j for j in range(2 * i + 2))
            if is_palindromes(N1 * N1):
                yield N1 * N1
            if is_palindromes(N2 * N2):
                yield N2 * N2

def get_input(f):
    T = int(next(f))
    for _ in range(T):
        A, B = get_ints(f)
        yield A, B

def main():
    Fare_squares = set(all_above(4))
    for i, (A, B) in enumerate(get_input(sys.stdin)):
        print "Case #{0}:".format(i + 1), len(filter(lambda v:A<=v<=B, Fare_squares))

if __name__ == "__main__":
    main()
