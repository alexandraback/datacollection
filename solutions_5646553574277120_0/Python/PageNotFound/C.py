# -*- coding: utf-8 -*-
from sys import stdin, stdout
from copy import copy

stdin = open('C-small-attempt0.in', 'r')
stdout = open('C-small-attempt0.out', 'w')


def solve():
    C, D, V = map(int, stdin.readline().split())
    pre = map(int, stdin.readline().split())
    l = init(pre)
    cnt = 0
    for v in range(1, V+1):
        if v not in l:
            cnt += 1
            l = update(l, v)
    stdout.write('%d\n' % cnt)

def init(pre):
    s = set()
    for i in range(1 << len(pre)):
        tmp = 0
        for j in range(len(pre)):
            if (i & (1 << j)) > 0:
                tmp += pre[j]
        s.add(tmp)
    return list(s)

def update(l, v):
    ll = copy(l)
    for item in l:
        ll.append(item + v)
    return list(set(ll))

def need(pre, value):
    for item in pre:
        if value >= item:
            value -= item
    return value

T = int(stdin.readline())
for t in range(T):
    stdout.write('Case #%d: ' % (t+1))
    solve()