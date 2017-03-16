#!/usr/bin/env python3

# ZERO -> Z
# SIX -> X
# TWO -> W
# SEVEN -> S
# EIGHT -> G
# FIVE -> V
# THREE -> H
# FOUR -> U
# ONE -> O
# NINE -> I

numbers = [
    (0, 'Z', 'ZERO'),
    (6, 'X', 'SIX'),
    (2, 'W', 'TWO'),
    (7, 'S', 'SEVEN'),
    (8, 'G', 'EIGHT'),
    (5, 'V', 'FIVE'),
    (3, 'H', 'THREE'),
    (4, 'U', 'FOUR'),
    (1, 'O', 'ONE'),
    (9, 'I', 'NINE'),
]

def remove_word(counts, word):
    for letter in word:
        counts[letter] -= 1

T = int(input())
for t in range(T):
    word = input()
    counts = {}
    for letter in word:
        if letter in counts:
            counts[letter] += 1
        else:
            counts[letter] = 1
    digit_counts = {}
    for digit, letter, word in numbers:
        count = 0
        while letter in counts and counts[letter]:
            remove_word(counts, word)
            count += 1
        digit_counts[digit] = count
    for v in counts.values():
        assert v == 0
    answer = ''
    for digit in range(10):
        answer += str(digit) * digit_counts[digit]
    print('Case #{}: {}'.format(t+1, answer))
