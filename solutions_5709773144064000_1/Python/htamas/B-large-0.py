#!/usr/bin/env python3

import math

T = int(input())
for case in range(1, T+1):
    C, F, X = (float(i) for i in input().split())
    n = max(math.floor(X/C-2/F), 0)
    ans = sum(C/(2+i*F) for i in range(n)) + X/(2+n*F)
    print("Case #{}: {:.7f}".format(case, ans))

