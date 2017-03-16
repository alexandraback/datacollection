#!/usr/bin/env python

from collections import defaultdict

def solve(S):
    counted_letters = defaultdict(int)

    for c in S:
        counted_letters[c] += 1

    numbers = defaultdict(int)
    while counted_letters['Z']:
        numbers[0] += 1
        for c in 'ZERO':
            counted_letters[c] -= 1
    while counted_letters['W']:
        numbers[2] += 1
        for c in 'TWO':
            counted_letters[c] -= 1
    while counted_letters['G']:
        numbers[8] += 1
        for c in 'EIGHT':
            counted_letters[c] -= 1
    while counted_letters['X']:
        numbers[6] += 1
        for c in 'SIX':
            counted_letters[c] -= 1
    while counted_letters['H']:
        numbers[3] += 1
        for c in 'THREE':
            counted_letters[c] -= 1
    while counted_letters['R']:
        numbers[4] += 1
        for c in 'FOUR':
            counted_letters[c] -= 1
    while counted_letters['F']:
        numbers[5] += 1
        for c in 'FIVE':
            counted_letters[c] -= 1
    while counted_letters['O']:
        numbers[1] += 1
        for c in 'ONE':
            counted_letters[c] -= 1
    while counted_letters['V']:
        numbers[7] += 1
        for c in 'SEVEN':
            counted_letters[c] -= 1
    while counted_letters['N']:
        numbers[9] += 1
        for c in 'NINE':
            counted_letters[c] -= 1
    assert(max(counted_letters.values()) == 0)


    num_string = ''
    for num in range(0, 10):
        num_string += (str(num) * numbers[num])

    return num_string

T = int(raw_input().strip())

for i in range(1, T+1):
    print ("Case #%d:" % i),
    S = raw_input().strip()
    print solve(S)
