#!/usr/bin/python3

def solve(k, c, s):
    ans = []
    for a in range(0, k, c):
        u = 0
        for i in range(min(k - a, c)):
            u = u * k + (a + i)
        ans.append(str(u + 1))
    if len(ans) <= s:
        return " ".join(ans)
    return "IMPOSSIBLE"


t = int(input())
for i in range(t):
    k, c, s = map(int, input().split())
    print("Case #%d:" % (i + 1), solve(k, c, s))
