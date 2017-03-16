#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# 1 == 1
# i == 2
# j == 3
# k == 4

q0, q1, q2, q3 = 1, 0, 0, 0

def mul(c):
    global q0, q1, q2, q3

    if c == 'i':
        q0, q1, q2, q3 = -q1, q0, q3, -q2
    if c == 'j':
        q0, q1, q2, q3 = -q2, -q3, q0, q1
    if c == 'k':
        q0, q1, q2, q3 = -q3, q2, -q1, q0

def solve(t):
    l, x = [int(i) for i in input().split()]
    L = input()

    global q0, q1, q2, q3
    i = 0

    # find i
    q0, q1, q2, q3 = 1, 0, 0, 0

    while (q0, q1, q2, q3) != (0, 1, 0, 0):
        if i >= 4 * l or i >= l * x:
            print("Case #{}:".format(t), 'NO')
            return

        c = L[i % l]
        i += 1
        mul(c)

    # find j
    q0, q1, q2, q3 = 1, 0, 0, 0
    i_0 = i

    while (q0, q1, q2, q3) != (0, 0, 1, 0):
        if i - i_0 > 4 * l or i >= l * x:
            print("Case #{}:".format(t), 'NO')
            return

        c = L[i % l]
        i += 1
        mul(c)

    # find k
    q0, q1, q2, q3 = 1, 0, 0, 0
    i_0 = i

    while (q0, q1, q2, q3) != (0, 0, 0, 1):
        if i - i_0 > 4 * l or i >= l * x:
            print("Case #{}:".format(t), 'NO')
            return

        c = L[i % l]
        i += 1
        mul(c)

    # remaining must be 1
    q0, q1, q2, q3 = 1, 0, 0, 0

    while i % l != 0 or (x - (i // l)) % 4 != 0:
        if i >= l * x:
            print("Case #{}:".format(t), 'NO')
            return
        c = L[i % l]
        i += 1
        mul(c)

    if (q0, q1, q2, q3) == (1, 0, 0, 0):
        print("Case #{}:".format(t), 'YES')
    else:
        print("Case #{}:".format(t), 'NO')


T = int(input())

for t in range(1, T+1):
    solve(t)

