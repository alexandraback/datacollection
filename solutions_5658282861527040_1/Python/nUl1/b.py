#!/usr/bin/python2
# coding: utf-8

from sys import stdin

T = int(stdin.readline().rstrip())

def masks(endb):
    cm = ''
    for c in endb:
        if c == '1':
            yield (cm + '0' + '*' * 32)[:32]
        cm += c


def cnt(am, bm, km):
    cm = ''
    for ac, bc in zip(am, bm):
        if ac == '*':
            if bc == '1':
                cm += '?'
            elif bc == '0':
                cm += '!'
            else:
                cm += bc
        elif bc == '*':
            if ac == '1':
                cm += '?'
            elif ac == '0':
                cm += '!'
            else:
                cm += ac
        elif bc == ac:
            cm += ac
        else:
            cm += '0'

    res = 1
    for cc, kc in zip(cm, km):
        if cc == '*':
            if kc == '*':
                res *= 4
            elif kc == '0':
                res *= 3
        elif cc == '?':
            if kc == '*':
                res *= 2
        elif cc == '!':
            if kc == '*' or kc == '0':
                res *= 2
            else:
                return 0
        elif kc != '*' and kc != cc:
            return 0
    return res


for ct in range(T):
    A, B, K = map(long, stdin.readline().split())

    ab = ('0' * 32 + bin(A)[2:])[-32:]
    bb = ('0' * 32 + bin(B)[2:])[-32:]
    kb = ('0' * 32 + bin(K)[2:])[-32:]

    ans = 0

    for am in masks(ab):
        for bm in masks(bb):
            for km in masks(kb):
                k = cnt(am, bm, km)
                ans += k

    print 'Case #{0}: {1}'.format(ct + 1, ans)
