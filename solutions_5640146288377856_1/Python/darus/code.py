#!/bin/python


def solve(R, C, W):

    if (W == 1):
        return R * C
    elif (W == C):
        return R - 1 + W

    return (R - 1) * int((C - 1)/W) + int((C - 1)/W) + W


T = int(input())

for i in range(0, T):
    R, C, W = [int(x) for x in input().split()]

    print("Case #", (i+1), ": ", solve(R, C, W), sep='')
    

