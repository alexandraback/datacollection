#!/usr/bin/env python

t = int(input())
for case in range(1,t+1):
    a, b = map(int,input().strip().split())
    ps = list(map(float,input().strip().split()))
    totalps = [0 for _ in range(a)]
    totalps[0] = ps[0]
    for i in range(1,a):
        totalps[i] = totalps[i-1]*ps[i]

    # press enter right away
    best = float(b+2)

    # backspace i times
    for i in range(a):
        cur = i + (b-a+i+1)*totalps[a-1-i] + (2*b-a+i+2)*(1-totalps[a-1-i])
        best = min(best, cur)

    print('Case #{}: {:.6f}'.format(case, best))
