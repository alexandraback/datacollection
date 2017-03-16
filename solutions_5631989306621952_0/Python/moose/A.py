#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Solution for https://code.google.com/codejam/contest/4304486/dashboard."""


def solve(word):
    """Get the last word of `word`."""
    last_word = word[0]
    for letter in word[1:]:
        if letter >= last_word[0]:
            last_word = letter + last_word
        else:
            last_word = last_word + letter
    return last_word


if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases+1):
        cipher = raw_input()
        print("Case #%i: %s" % (caseNr, solve(cipher)))
