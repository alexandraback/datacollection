#!/usr/bin/env python3

def solve(R, C, W):
    if W == 1:
        return R * C
    return ((C-1)//W + 1)*R - 1 + W

T = int(input())
for t in range(T):
    R, C, W = [int(x) for x in input().split(" ")]
    print("Case #" + str(t+1) +":", solve(R, C, W))
