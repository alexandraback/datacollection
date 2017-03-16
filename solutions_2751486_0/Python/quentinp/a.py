#!/usr/bin/env python3

import sys

def read_input():
    words = []
    with open(sys.argv[1]) as input_file:
        total = int(input_file.readline().strip())
        for l in input_file.readlines():
            word, n = l.strip().split()
            words.append((word, int(n)))
            
    assert(len(words) == total)
    return words

VOWELS = 'aeiou'

def has_n_consecutive(word, n, i, j):
    max_combo, combo = 0, 0
    for c in word[i:j+1]:
        if c in VOWELS:
            combo = 0
        else:
            combo += 1
            if combo > max_combo: max_combo = combo

    return max_combo >= n

def get_nvalue_naive(word, n):
    substrings = []
    for i in range(len(word)):
        for j in range(len(word)):
            if has_n_consecutive(word, n, i, j) and not (i, j) in substrings:
                substrings.append((i, j))

    return len(substrings)

words = read_input()

i = 0
for word, n in words:
    print("Case #{}: {}".format(i+1, get_nvalue_naive(word, n)))
    i += 1
