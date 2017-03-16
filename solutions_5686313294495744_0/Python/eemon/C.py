#!/usr/bin/env python
# -*- coding: utf-8 -*-

T = int(input())
for case in range(T):
    N = int(input())
    topics = [input().split() for i in range(0,N)]
    ans = 0

    for i in range(2**N):
        first = set()
        second = set()

        for  j in range(N):
            if i & (1<<j) > 0:
                first.add(topics[j][0])
                second.add(topics[j][1])

        # 残りを作れる？
        count = 0
        for  j in range(N):
            if i & (1<<j) == 0:
                count+= 1
                if topics[j][0] not in first or topics[j][1] not in second:
                    break
        else:
            ans = max(ans, count)

    print("Case #{0}: {1}".format(case+1, ans))
