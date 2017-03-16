#!/usr/bin/env python3

import sys
from collections import *




TC = int(input())
for tc in range(1, TC+1):
    n = int(input())

    id_map = {}
    topics = []

    for _ in range(n):
        words = input().split(' ')
        words = ['{}_{}'.format(i,w) for i, w in enumerate(words)]
        for i in range(len(words)):
            if words[i] not in id_map:
                new_id = len(id_map)
                id_map[words[i]] = new_id
            words[i] = id_map[words[i]]
        topics.append(words)

    tn = len(topics)

    result = 0

    for bm in range(1<<tn):
        words_avail = set()
        for t in range(tn):
            if bm & (1<<t):
                words_avail.add(topics[t][0])
                words_avail.add(topics[t][1])

        cnt = 0
        ok = True
        for t in range(tn):
            if not bm & (1<<t):
                if topics[t][0] not in words_avail or topics[t][1] not in words_avail:
                    ok = False
                    break
                cnt += 1

        if ok:
            result = max(result, cnt)

    print('Case #{}: {}'.format(tc, result))
