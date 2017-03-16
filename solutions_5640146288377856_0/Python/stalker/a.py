#!/usr/bin/env python3

from math import ceil
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

def solve(R,C,W):
    result = R * ceil( (C-(W-1)) / W)
    if C % W == 0:
        return result + W -1
    else:
        return result + W


if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        R,C,V = read_ints()
        R = solve(R,C,V)
        print("Case #{}: {}".format(c+1,R))
