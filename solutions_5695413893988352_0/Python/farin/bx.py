#!/usr/bin/env python3


def solve(c, j):
    # if len(c.replace('?', '')) == 0 and len(j.replace('?', '')) == 0:
    #     return c + ' ' + j
    stack = [c + ' ' + j]
    bd = 99999999
    bc, bj = None, None
    bt = None
    while stack:
        t = stack.pop()
        if '?' not in t:
            a, b = map(int, t.split(' '))
            d = abs(a-b)
            if d < bd:
                bd = d
                bc, bj = a, b
                bt = t
            elif d == bd:
                if a < bc:
                    bc, bj = a, b
                    bt = t
                elif a == bc:
                    if b < bj:
                        bc, bj = a, b
                        bt = t

        else:
            idx = t.index('?')
            for i in range(10):
                stack.append(t[:idx]+str(i)+t[idx+1:])
    return bt


testcases = int(input())

for case_n in range(1, testcases+1):
    #case_data = map(int, input().split())
    case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
