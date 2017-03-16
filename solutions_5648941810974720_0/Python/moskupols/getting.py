#!/usr/bin/env python3

import numpy as np

words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

coeff = np.zeros((26, len(words)))

for i, word in enumerate(words):
    for c in word:
        o = ord(c) - ord('A')
        coeff[o, i] += 1

def solve(s):
    b = np.zeros((26,))
    for o in map(ord, s):
        b[o - ord('A')] += 1
    return np.linalg.lstsq(coeff, b)[0].round().astype(int).reshape((10,))

n = int(input())
for i in range(1, n + 1):
    solution = solve(input())
    print('Case #', i, ': ', sep='', end='')
    for i, k in enumerate(solution):
        print(str(i) * k, end='')
    print()

