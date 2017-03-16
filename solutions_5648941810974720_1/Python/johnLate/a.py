#!/usr/bin/env python3

import sys
from collections import *


def count_chars(string):
    cnt = defaultdict(lambda: 0)
    for char in string:
        cnt[char] += 1
    return cnt


number_names = ["ZERO", "ONE", "TWO", "THREE", "FOUR",
                "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
number_char_count = [count_chars(n) for n in number_names]


T = int(input())
for t in range(1, T+1):
    Q = input()

    Q_cnt = defaultdict(lambda: 0)
    for c in Q:
        Q_cnt[c] += 1

    order = [0, 6, 4, 5, 8,
             3, 2, 7, 9, 1]

    result = {}

    for digit in order:
        sub = 10**10
        for char, count in number_char_count[digit].items():
            sub = min(sub, Q_cnt[char] // count)

        if sub == 0:
            continue

        result[digit] = sub
        for char, count in number_char_count[digit].items():
            Q_cnt[char] -= count * sub

    print('Case #{}: {}'.format(
        t,
        ''.join([chr(ord('0') + digit) * count
                 for digit, count in sorted(result.items())])
        ))
