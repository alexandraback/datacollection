#! /usr/bin/env python

from fractions import gcd

T = int(input())

for tt in range(1, T+1):
    p, q = [int(x) for x in input().split('/')]
    d = gcd(p, q)
    p //= d
    q //= d
    if bin(q).count('1') != 1:
        print("Case #{}: impossible".format(tt))
        continue

    for i in range(41):
        if (1 << i) * p >= q:
            print("Case #{}: {}".format(tt, i))
            break
    else:
        print("Case #{}: impossible".format(tt))
        
