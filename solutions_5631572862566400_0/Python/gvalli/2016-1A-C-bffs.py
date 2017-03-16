#! /#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

fh = open(sys.argv[1], 'r')
T = int(fh.readline())  # number of test cases
for t in range(T):
    N = int(fh.readline())  # number of kids
    BFFs = [int(v) for v in fh.readline().split()]  # BFFs of each kid

    # breadth first search
    maxlen = 0
    best = None
    for n in range(1, N + 1):
        used = list()
        cycles = list()
        queue = [n]
        dists = [0] * N
        while queue:
            cur = queue.pop() - 1  # current kid
            adj = BFFs[cur]  # bff of current kid
            used.append(cur + 1)
            if dists[adj - 1] == 0:
                dists[adj - 1] += 1
                if adj not in used:
                    queue.append(adj)
                else:
                    cycles.append(adj)
            else:
                cycles.append(adj)
        # check for loops
        lencycles = list()
        maxcycle = 0
        for i in cycles:
            curr = BFFs[i - 1]
            num = 1
            while curr != i:
                num += 1
                curr = BFFs[curr - 1]
            lencycles.append(num)
            if num > maxcycle:
                maxcycle = num
        # print n, used, cycles, lencycles
        if maxcycle > 2:
            # only the largest cycle is the good one
            res = maxcycle
        elif maxcycle == 2:
            # loop 2 at the end can add a branch pointing to it
            addlen = 0
            if used[-2] in cycles:
                end = used[-1]
                for a in range(1, N + 1):
                    thislen = 0
                    if a not in used:
                        # print a
                        done = list()
                        call = [a]
                        while call:
                            now = call.pop() - 1
                            fri = BFFs[now]
                            done.append(now + 1)
                            if fri == end:
                                thislen = len(done)
                            elif fri in used:
                                break
                            elif fri in done:
                                break
                            else:
                                call.append(fri)
                    if thislen > addlen:
                        addlen = thislen
            res = len(used) + addlen
        else:
            res = len(used)

        # check if longer
        if res > maxlen:
            maxlen = res

    print('Case #{:d}: {}'.format(t + 1, maxlen))
