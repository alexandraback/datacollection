#!/usr/bin/env python
# -*- coding: utf-8 -*-

T = int(input())
for case in range(T):
    S = list(input())
    ans = [S[0]]

    for s in S[1:]:
        if ans[0] <= s:
            ans = [s]+ ans
        else:
            ans.append(s)

    print("Case #{0}: {1}".format(case+1, ''.join(ans)))
