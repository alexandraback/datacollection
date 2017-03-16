#!/usr/bin/env python2

import sys

def solve(word):
    word = list(word)
    result = [word.pop(0)]
    while len(word):
        if ord(word[0]) >= ord(result[0]):
            result = [word[0]] + result
        else:
            result = result + [word[0]]
        word.pop(0)
    return ''.join(result)
    # for c in word:


count = int(sys.stdin.readline().strip())

current = 1

while current <= count:
    print 'Case #{}: {}'.format(current, solve(sys.stdin.readline().strip()))
    current += 1