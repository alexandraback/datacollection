#! /usr/bin/env python

from sys import stdin
import sys
from collections import defaultdict

digits = [('ZERO', 'Z', 0),
          ('SIX', 'X', 6),
          ('TWO', 'W', 2),
          ('FOUR', 'U', 4),
          ('ONE', 'O', 1),
          ('THREE', 'R', 3),
          ('FIVE', 'F', 5),
          ('SEVEN', 'S', 7),
          ('EIGHT', 'H', 8),
          ('NINE', 'I', 9)]

ntest = input()

for test in xrange(ntest):
    S = stdin.readline().strip()
    letters = defaultdict(lambda: 0)
    for c in S:
        letters[c] += 1
    solution = [0] * 10
    for digit, flag, number in digits:
        n = letters[flag]
        solution[number] = n
        for c in digit:
            letters[c] -= n
    ans = "".join(str(i) * solution[i] for i in xrange(10))
    print "Case #{}: {}".format(test + 1, ans)

