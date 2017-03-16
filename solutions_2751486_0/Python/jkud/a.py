#!/usr/bin/env python

import sys

def solve(word, N):
    word = ''.join(' ' if l in 'aeiou' else '1' for l in word)
    t = '1' * N
    l = len(word)
    r = 0
    for i in range(0, l):
        for j in range(i, l):
            if t in word[i:j+1]:
                r += 1
    return r

T = int(raw_input())
for t in range(T):
    print >> sys.stderr, t
    word, N = raw_input().split()
    N = int(N)
    print "Case #%d: %d" % (t+1, solve(word, N))
