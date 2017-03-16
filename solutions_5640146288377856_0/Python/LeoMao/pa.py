#! /usr/bin/env python

T = int(input())

for t in range(1, T+1):
    r, c, w = [int(x) for x in input().split()]
    tri, left = divmod(c, w) # tries
    ans = r * tri + bool(left) + w - 1

    print("Case #{}: {}".format(t, ans))
