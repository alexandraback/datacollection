#!/usr/bin/python2.7

def solve_case():
    s = raw_input().split(' ')
    n = eval(s[0])
    s = s[1]
    cur = 0
    ans = 0
    for i in range(len(s)):
        cnt = eval(s[i])
        if cnt > 0:
            if cur < i:
                ans += i - cur
                cur = i
            cur += cnt
    return ans

t = input()
for i in range(t):
    r = solve_case()
    s = "Case #" + str(i + 1) + ": " + str(r)
    print s
