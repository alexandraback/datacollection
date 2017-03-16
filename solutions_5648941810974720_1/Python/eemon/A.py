#!/usr/bin/env python
# -*- coding: utf-8 -*-
from collections import Counter

T = int(input())
for case in range(T):
    S = list(input())
    counter = Counter(S)
    ans = []

    if counter['G'] > 0:
        ans += [8] * counter['G']
        counter['E'] -= counter['G']
        counter['I'] -= counter['G']
        counter['H'] -= counter['G']
        counter['T'] -= counter['G']
        counter['G'] = 0

    if counter['W'] > 0:
        ans += [2] * counter['W']
        counter['T'] -= counter['W']
        counter['O'] -= counter['W']
        counter['W'] = 0

    if counter['U'] > 0:
        ans += [4] * counter['U']
        counter['F'] -= counter['U']
        counter['O'] -= counter['U']
        counter['R'] -= counter['U']
        counter['U'] = 0

    if counter['X'] > 0:
        ans += [6] * counter['X']
        counter['S'] -= counter['X']
        counter['I'] -= counter['X']
        counter['X'] = 0

    if counter['Z'] > 0:
        ans += [0] * counter['Z']
        counter['E'] -= counter['Z']
        counter['R'] -= counter['Z']
        counter['O'] -= counter['Z']
        counter['Z'] = 0

    if counter['F'] > 0:
        ans += [5] * counter['F']
        counter['I'] -= counter['F']
        counter['V'] -= counter['F']
        counter['E'] -= counter['F']
        counter['F'] = 0

    if counter['S'] > 0:
        ans += [7] * counter['S']
        counter['E'] -= counter['S'] * 2
        counter['V'] -= counter['S']
        counter['N'] -= counter['S']
        counter['S'] = 0

    if counter['T'] > 0:
        ans += [3] * counter['T']
        counter['H'] -= counter['T']
        counter['R'] -= counter['T']
        counter['E'] -= counter['T'] * 2
        counter['T'] = 0

    if counter['I'] > 0:
        ans += [9] * counter['I']
        counter['N'] -= counter['I'] * 2
        counter['E'] -= counter['I']
        counter['I'] = 0

    if counter['O'] > 0:
        ans += [1] * counter['O']
        counter['N'] -= counter['O'] * 2
        counter['E'] -= counter['O']
        counter['O'] = 0

    print("Case #{0}: {1}".format(case+1, ''.join(map(str,sorted(ans)))))
