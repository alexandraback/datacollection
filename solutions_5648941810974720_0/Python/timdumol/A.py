#-*- encoding: utf-8 -*-

from __future__ import print_function
from __future__ import absolute_import
from __future__ import unicode_literals
from __future__ import division

from collections import Counter, defaultdict

nums = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']

n_cases = int(input())

for ctr in range(n_cases):
    counts = Counter()
    s = input()
    for letter in s:
        counts[letter] += 1

    ans = ""
    ans += "0" * counts['Z']
    cnt = counts['Z']
    for letter in 'ZERO':
        counts[letter] -= cnt

    n_dig = Counter()
    ans += "2" * counts['W']
    n_dig[2] = counts['W']

    for letter in 'TWO':
        counts[letter] -= n_dig[2]

    ans += "4" * counts['U']
    n_dig[4] = counts['U']

    for letter in 'FOUR':
        counts[letter] -= n_dig[4]

    ans += "1" * counts['O']
    n_dig[1] = counts['O']

    for letter in 'ONE':
        counts[letter] -= n_dig[1]

    ans += "3" * counts['R']
    n_dig[3] = counts['R']

    for letter in 'THREE':
        counts[letter] -= n_dig[3]

    ans += '6' * counts['X']
    n_dig[6] = counts['X']

    for letter in 'SIX':
        counts[letter] -= n_dig[6]

    ans += "8" * counts['G']
    n_dig[8] = counts['G']

    for letter in 'EIGHT':
        counts[letter] -= n_dig[8]

    ans += "5" * counts['F']
    n_dig[5] = counts['F']

    for letter in 'FIVE':
        counts[letter] -= n_dig[5]

    ans += "7" * counts['S']
    n_dig[7] = counts['S']

    for letter in 'SEVEN':
        counts[letter] -= n_dig[7]

    ans += "9" * counts['I']
    n_dig[9] = counts['I']

    for letter in 'NINE':
        counts[letter] -= n_dig[9]

    print('Case #%d: %s' % (ctr + 1, ''.join(sorted(ans))))
