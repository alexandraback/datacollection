#!/usr/bin/python3


T = int(input())

for case in range(1, T + 1):
    R, C, W = map(int, input().split())
    ans = R * (C//W) 
    if (C % W) == 0: ans += W - 1
    else: ans += W
    print("Case #%d: %d" % (case, ans))

