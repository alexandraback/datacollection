#! /usr/bin/env python
#-*- coding: utf-8 -*-
import sys,requests,json,os,traceback,datetime
reload(sys)
sys.setdefaultencoding('utf8')
sys.setrecursionlimit(10000)

def dfs(x, step, cao):
    global visit, ans, duos
    # print x+1, nxt[x]+1, step
    visit[x] = step
    visit2[x] = cao

    if visit[nxt[x]] and visit2[nxt[x]] == cao:
        # print 'find circle'
        ans = max(ans, step - visit[nxt[x]] + 1)
        if nxt[nxt[x]] == x:
            # print "find duo", (x, nxt[x])
            duos.append((x, nxt[x]))
    elif not visit2[nxt[x]] and not visit[nxt[x]]:
        dfs(nxt[x], step+1, cao)

def find_long(x, step, ban):
    res = step
    for v in bf[x]:
        if v == ban:
            continue
        res = max(res, find_long(v, step+1, ban))
    return res

ans = None
visit = None
visit2 = None
duos = None
nxt = None
bf = None

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d:" % Case,
    n = int(raw_input())
    nxt = map(lambda x: int(x)-1, raw_input().split(' '))
    # print nxt
    bf = [ [] for i in range(n) ]

    for i, v in enumerate(nxt):
        bf[v].append(i)

    visit = [ 0 for i in range(n) ]
    visit2 = [ 0 for i in range(n) ]
    ans = 0
    duos = []

    for i in range(n):
        if not visit[i]:
            dfs(i, 1, i+1)

    # print ans, duos
    chain = 0
    for duo in duos:
        t1 = find_long(duo[0], 1, duo[1])
        t2 = find_long(duo[1], 1, duo[0])
        # print (duo[0], t1), (duo[1], t2)
        chain += t1 + t2

    print max(ans, chain)
