#!/bin/python3

T = int(input())


for t in range(1, T + 1):
    K, C, S = [int(x) for x in input().split()]

    if S == K:
        print("Case #{}: {}".format(t, ' '.join([str(x) for x in range(1, K + 1)])))
