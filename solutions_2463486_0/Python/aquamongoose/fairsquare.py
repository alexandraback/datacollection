#!/usr/bin/env python3
# Bill Cooperman (aquamongoose)
# Google Code Jam Qualification Round
# Problem C
from math import sqrt

T = int(input())
eps = 1e-9

def pal(n):
    return str(n) == str(n)[::-1]

for i in range(T):
    print("Case #{}:".format(i+1),end=' ')
    A, B = [int(x) for x in input().split()]
    ans = 0
    for i in range(A, B+1):
        if int(sqrt(i)+eps)**2 == i and pal(i) and pal(int(sqrt(i)+eps)):
            ans += 1
    print(ans)
