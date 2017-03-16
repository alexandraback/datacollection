#!/usr/bin/env python2

import os, sys, heapq
from heapq import *

input = 'i'
if len(sys.argv) > 1:
    input = sys.argv[1]

f = open(input, 'r')

T = int(f.readline()[:-1])

score = 0

for i in range(T):
    s = f.readline()[:-1]
    N = int(s)
    st = []
    for j in range(N):
        s = f.readline()[:-1]
        ary = s.split(' ')
        st.append([int(ary[0]), int(ary[1]), 0, 0])
    ans = N
    score = 0
    noans = 0
    l = len(st)
    while score < 2 * N:
        flag = 0
        small = 1 << 30
        for j in range(l):
            if small > st[j][1]:
                small = st[j][1]
            if score >= st[j][1] and st[j][3] == 0:
                if st[j][2] == 0:
                    score += 2
                else:
                    score += 1
                st[j][2] = 2
                flag = 1
                break
        if flag > 0:
            continue
        h = []
        for j in range(N):
            if st[j][2] + st[j][3] == 0 and score >= st[j][0]:
                heappush(h, (-st[j][1], st[j]))
        #print 'small = %d' % small
        #print st, score
        #print h
        while score < small and len(h) > 0:
            item = heappop(h)
            item[1][2] = 1
            score += 1
            ans += 1
            #print 'score get 1 by ' + str(st[j])

        if score < small:
            noans = 1
            break
    if noans > 0:
        print 'Case #%d: Too Bad' % (i+1)
    else:
        print 'Case #%d: %d' % (i+1, ans)

