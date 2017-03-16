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

def solve(I,S):
    acc = 0
    res = 0
    n = len(S)

    for i in range(n):
        if i > acc:
            acc += 1
            res += 1
        acc += int(S[i])
    return res


if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        I = read_words()
        R = solve(int(I[0]),I[1])
        print("Case #{}: {}".format(c+1,R))
