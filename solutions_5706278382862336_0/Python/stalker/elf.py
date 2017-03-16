#!/usr/bin/env python3

################################################################################

def read_int():
    return int(input())

def read_words():
    return input().split()

def read_ints():
    return list(map(int,read_words()))

def read_floats():
    return list(map(float,read_words()))

################################################################################

import fractions as f


def log(n):
    limit = 1
    result = 0

    if n == 0:
        return "impossible"
    
    while n >= limit:
        limit *= 2
        result += 1
    
    return 40 - (result-1)

def solve(p):

    p = p * f.Fraction(2**40,1)

    if p.denominator != 1:
        return "impossible"
    else:
        return log(p.numerator)


if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        P = f.Fraction(input())
        R = solve(P)
        print("Case #{}: {}".format(c+1,R))
