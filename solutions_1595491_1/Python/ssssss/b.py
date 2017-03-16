#!/usr/bin/python3

import sys


T=int(sys.stdin.readline())

for i in range(1,T+1):
    line = [int(x) for x in sys.stdin.readline().split()]
    N = line[0]
    S = line[1]
    p = line[2]
    t = 3*p - 2
    if p == 0:
        t = 0
    r = 0
    for j in line[3:]:
        if j >= t:
            r += 1
        elif j >= t-2 and S > 0 and j >=3:
            r += 1
            S -= 1
    print("Case #%s: %s" %(i,r))
            

