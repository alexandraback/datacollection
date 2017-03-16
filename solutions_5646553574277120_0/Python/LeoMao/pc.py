#! /usr/bin/env python

T = int(input())

def solve(c, deno, v):
    ans = []
    canp = 1
    for d in deno:
        for i in range(1, c+1):
            canp |= canp << d
    bbb = bin(canp)[2:2+v+1]
    for i in range(1, v+1):
        if len(bbb) <= i or bbb[i] == '0':
            ans.append(i)
            for j in range(1, c+1):
                canp |= canp << i
            bbb = bin(canp)[2:2+v+1]
    return len(ans)


for t in range(1, T+1):
    c, d, v = [int(x) for x in input().split()]
    deno = [int(x) for x in input().split()]

    ans = solve(c, deno, v)

    print("Case #{}: {}".format(t, ans))
