#!/usr/bin/env python

import numpy as np

for i in xrange(int(raw_input())):
    s =  raw_input()
    letterDict = {letter : s.count(letter) for letter in set(s)}
    digits = [0]*10
    if s.count('Z') != 0:
        digits[0] = s.count('Z')
        for letter in "ZERO":
            letterDict[letter] -= digits[0]

    if s.count('W') != 0:
        digits[2] = s.count('W')
        for letter in "TWO":
            letterDict[letter] -= digits[2]

    if s.count('U') != 0:
        digits[4] = s.count('U')
        for letter in "FOUR":
            letterDict[letter] -= digits[4]

    if s.count('X') != 0:
        digits[6] = s.count('X')
        for letter in "SIX":
            letterDict[letter] -= digits[6]

    if s.count('G') != 0:
        digits[8] = s.count('G')
        for letter in "EIGHT":
            letterDict[letter] -= digits[8]

    s = ''.join(letter * letterDict[letter] for letter in letterDict.keys())
    letterDict = {letter : s.count(letter) for letter in set(s)}

    if s.count('O') != 0:
        digits[1] = s.count('O')
        for letter in "ONE":
            letterDict[letter] -= digits[1]

    if s.count('T') != 0:
        digits[3] = s.count('T')
        for letter in "THREE":
            letterDict[letter] -= digits[3]

    if s.count('F') != 0:
        digits[5] = s.count('F')
        for letter in "FIVE":
            letterDict[letter] -= digits[5]

    if s.count('S') != 0:
        digits[7] = s.count('S')
        for letter in "SEVEN":
            letterDict[letter] -= digits[7]

    s = ''.join(letter * letterDict[letter] for letter in letterDict.keys())
    letterDict = {letter : s.count(letter) for letter in set(s)}

    if s != '':
        digits[9] = s.count('I')

    p = ''.join([str(k)*digits[k] for k in xrange(10)])
    print "Case #{}: {}".format(i+1, p)

