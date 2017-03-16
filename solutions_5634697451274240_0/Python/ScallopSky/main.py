#! /usr/bin/env python

def find_last(s):
    last = -1
    for i in range(n):
        if s[i] == '-':
            last = i
    return last

def flip(s, nxt):
    s = s[nxt::-1] + s[nxt+1:]
    t = ''
    for i in range(n):
        if i > nxt:
            t += s[i]
            continue
        if s[i] == '+':
            t += '-'
        else:
            t += '+'
    return t

def dfs(s, step):
    global best
    # print "VISIT", s, step
    visit[s] = step
    if s == final:
        best = step
        return step

    ans = 1e10
    for i in range(find_last(s), -1, -1):
        t = flip(s, i)
        # print step, 'Flip', t, i
        if step + 1 < best and (t not in visit or (t in visit and step+1 < visit[t])):
            ans = min(ans, dfs(t, step+1))
    return ans

visit = {}
best = 0

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d: " % Case,
    s = raw_input()
    n = len(s)
    final = '+'*n
    best = 1e10
    visit = {}

    print dfs(s, 0)
