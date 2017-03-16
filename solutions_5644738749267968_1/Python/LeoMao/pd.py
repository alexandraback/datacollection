#! /usr/bin/env python

def cal(blocks, n):
    buf = 0
    ans = n
    for b in blocks:
        if b[1]:
            buf += 1
        else:
            if buf > 0:
                buf -= 1
            else:
                ans -= 1
    return ans


T = int(input())
for t in range(1, T+1):
    n = int(input())
    blocks = []
    blocks += [(float(x), 1) for x in input().split()]
    blocks += [(float(x), 0) for x in input().split()]
    blocks.sort(key=lambda x: x[0])
    ans = n - cal(blocks, n)
    cans = cal(reversed(blocks), n)
    print("Case #{}: {} {}".format(t, cans, ans))
