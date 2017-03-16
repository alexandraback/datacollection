#!/usr/bin/env python3

from math import log

def last(S):
    # Start with the first letter.
    chars = list(S[0:1])

    # For each other letter:
    for letter in S[1:]:
        # If this is equal to or greater than the greatest letter
        # so far, then prepend it, else append it.
        if letter >= chars[0]:
            chars.insert(0, letter)
        else:
            chars.append(letter)

    return ''.join(chars)

def oracle(S, result):
    # A last word is bad if the first letter is not greatest.
    assert(result[0] == max(S))

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        S = input()
        result = last(S)
        oracle(S, result)

        print("Case #{}: {}".format(i, last(S)))
