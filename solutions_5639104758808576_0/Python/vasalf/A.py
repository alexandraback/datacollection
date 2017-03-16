#!/usr/bin/python3

t = int(input())

for i in range(t):
    sm_s, s = input().split()
    sm = int(sm_s)
    num = 0
    ans = 0
    for j in range(sm + 1):
        if num < j:
            ans += j - num
            num = j
        num += int(s[j])
    print("Case #%d: %d" % (i + 1, ans))
