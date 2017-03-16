#!/usr/bin/env python
# Python 3

import platform
assert platform.python_version_tuple()[0] == '3'


def solution(s):
    charcount = {}

    for char in s:
        if char in charcount:
            charcount[char] += 1
        else:
            charcount[char] = 1

    def dropwords(by_char, drop_chars):
        if by_char in charcount:
            amount = charcount[by_char]
            for dc in drop_chars:
                if dc in charcount:  # fails only if dropping a word that wasn't in original input, but where its key did appear (thanks to another number) in the original input
                    charcount[dc] -= amount
                    assert charcount[dc] >= 0

            charcount[by_char] -= amount
            assert charcount[by_char] == 0
            return amount
        else:
            return 0

    twos = dropwords('W', ['T', 'O'])
    fours = dropwords('U', ['F', 'O', 'R'])
    sixes = dropwords('X', ['S', 'I'])
    eights = dropwords('G', ['E', 'I', 'H', 'T'])
    zeroes = dropwords('Z', ['E', 'R', 'O'])
    sevens = dropwords('S', ['E', 'V', 'E', 'N'])
    threes = dropwords('T', ['H', 'R', 'E', 'E'])
    fives = dropwords('V', ['F', 'I', 'E'])
    nines = dropwords('I', ['N', 'N', 'E'])
    ones = dropwords('O', ['N', 'E'])

    return '0' * zeroes + '1' * ones + '2' * twos + '3' * threes + '4' * fours + '5' * fives + '6' * sixes + '7' * sevens + '8' * eights + '9' * nines

# Taken from https://code.google.com/codejam/tutorials.html
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# Customize the lines in the for loop to suit the input format
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    s = input()
    print("Case #{}: {}".format(i, solution(s)))
