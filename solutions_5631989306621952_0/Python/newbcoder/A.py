#!/usr/bin/python

import sys

def find_last(letters):
    outw = letters.pop(0)
    for letter in letters:
        if letter >= outw[0]:
            outw = letter + outw
        else:
            outw += letter
    return outw

with open(sys.argv[1], 'r') as f:
    cases = int(f.readline())
    for case in range(cases):
        word = list(f.readline().strip())
        ans = find_last(word)
        print("Case #{:}: {:}".format(case+1, ans))


