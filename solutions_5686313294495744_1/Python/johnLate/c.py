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

    adjx = [set() for _ in range(tn)]
    adjy = [set() for _ in range(tn)]

    for a in range(tn):
        for b in range(a+1, tn):
            if topics[a][0] == topics[b][1] or topics[a][1] == topics[b][0]:
                continue
            if topics[a][0] == topics[b][0]:
                adjx[a].add(b)
                adjx[b].add(a)
            if topics[a][1] == topics[b][1]:
                adjy[a].add(b)
                adjy[b].add(a)

    word_avail = set()
    done = set()
    for t in range(tn):
        if len(adjx[t]) == 0 or len(adjy[t]) == 0:
            done.add(t)
            word_avail.add(topics[t][0])
            word_avail.add(topics[t][1])

    original = 0
    original += len(done)

    fake = set()
    for t in range(tn):
        if t in done: continue

        if topics[t][0] in word_avail and topics[t][1] in word_avail:
            fake.add(t)
            done.add(t)

    choose_orig = set()
    for t in range(tn):
        if t in done: continue

        if topics[t][0] not in word_avail and topics[t][1] not in word_avail:
            original += 1
            choose_orig.add(t)
            word_avail.add(topics[t][0])
            word_avail.add(topics[t][1])
            done.add(t)

    for t in range(tn):
        if t in done: continue

        if topics[t][0] in word_avail and topics[t][1] in word_avail:
            fake.add(t)
            done.add(t)

    for t in range(tn):
        if t in done: continue

        if topics[t][0] not in word_avail:
            done.add(t)
            word_avail.add(topics[t][0])
            original += 1
        elif topics[t][1] not in word_avail:
            done.add(t)
            word_avail.add(topics[t][1])
            original += 1
        else:
            done.add(t)


    result = tn - original
    print('Case #{}: {}'.format(tc, result))
