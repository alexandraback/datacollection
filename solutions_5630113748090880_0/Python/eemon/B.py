#!/usr/bin/env python
# -*- coding: utf-8 -*-
from collections import Counter

T = int(input())
for case in range(T):
    N = int(input())
    nums = Counter()

    for n in range(2*N-1):
        S = map(int,input().split())
        nums += Counter(S)
    ans = []
    for num,count in nums.items():
        if count % 2 == 1:
            ans.append(num)
    print("Case #{0}: {1}".format(case+1, ' '.join(map(str,sorted(ans)))))
