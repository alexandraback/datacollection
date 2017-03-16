#!/usr/bin/env python3


def solve(word):
    res = ""
    for c in word:
        res = max(c + res, res + c)
    return res


T = int(input())
for t in range(1, T + 1):
    word = input()
    ans = solve(word)
    print("Case #{}: {}".format(t, ans))
