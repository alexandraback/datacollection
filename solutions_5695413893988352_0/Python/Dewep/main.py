#!/usr/bin/env python3

import itertools

def solve(s1, s2):
    pos_s1 = [i for i, ltr in enumerate(s1) if ltr == '?']
    pos_s2 = [i for i, ltr in enumerate(s2) if ltr == '?']
    values_s1 = itertools.product("0123456789", repeat=len(pos_s1))
    values_s2 = itertools.product("0123456789", repeat=len(pos_s2))

    min_s1 = []
    min_s2 = []
    min_value = 9999
    n1 = list(s1)
    n2 = list(s2)

    for positions_1 in values_s1:
        for i in range(len(pos_s1)):
            n1[pos_s1[i]] = positions_1[i]
        values_s2 = itertools.product("0123456789", repeat=len(pos_s2))
        for positions_2 in values_s2:
            for i in range(len(pos_s2)):
                n2[pos_s2[i]] = positions_2[i]
            tmp_n1 = int("".join(n1))
            tmp_n2 = int("".join(n2))
            tmp_value = abs(tmp_n1 - tmp_n2)
            if min_value > tmp_value:
                min_s1 = list(n1)
                min_s2 = list(n2)
                min_value = tmp_value

    return min_s1, min_s2

T = int(input())

for t in range(0, T):
    s1, s2 = input().split()
    n1, n2 = solve(s1, s2)
    print("Case #%d:" % (t + 1), "".join(n1), "".join(n2))
