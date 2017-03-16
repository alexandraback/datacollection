#!/usr/bin/python3

def solve(s):
    s = list(s)
    n = len(s)
    ans = 0
    for i in range(n - 1):
        if s[i] != s[i + 1]:
            ans += 1
    if s[-1] == '-':
        ans += 1
    return ans


t = int(input())
for i in range(t):
    print("Case #%d: %d" % (i + 1, solve(input())))
