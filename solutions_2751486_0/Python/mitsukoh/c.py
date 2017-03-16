#!/usr/bine/env python3
# coding: utf-8

from itertools import combinations

R, N, M, K = 0, 0, 0, 0
A = []
cand = []
check = {}

def fact(n):
    ret = {}
    for i in range(2, n):
        if i * i > n:
            break
        if n % i != 0:
            continue
        ret[i] = 0
        while n % i == 0:
            ret[i] += 1
            n = int(n / i)
    if n > 1:
        ret[n] = 1
    return ret

def make_cand(pos, last, a):
    if pos == N:
        cand.append(tuple(a[:]))
        return
    for i in range(last, 6):
        a.append(i)
        make_cand(pos+1, i, a[:])
        a.pop()

def mul(l):
    ret = 1
    for i in l:
        ret *= i
    return ret

def make_can(c):
    can = set()
    for i in range(len(c)+1):
        for l in combinations(c, i):
            can.add(mul(l))
    return can

def init():
    make_cand(0, 2, [])
    for c in cand:
        check[c] = make_can(c)

def solve():
    for c in reversed(cand):
        ok = True
        for a in A:
            if a not in check[c]:
                ok = False
        if ok:
            return ''.join(map(str, c))
    return '222'

input()
R, N, M, K = list(map(int, input().split(' ' )))
init()
print('Case #1:')
for i in range(R):
    A = list(map(int, input().split(' ')))
    print(solve())
