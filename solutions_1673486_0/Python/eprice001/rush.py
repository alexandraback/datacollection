#!/usr/bin/python

import sys
import fileinput
import string

input = fileinput.input()

T = int(input.next().strip())

for tcase in xrange(T):
    print 'Case #%d:' % (tcase + 1),
    typed, total = map(int, input.next().split())
    probs = map(float, input.next().split())

    prob = 1
    enum = total + 1
    for i in range(typed):
        prob *= probs[i]
        enum = min(enum + 1,
                   prob * (total - i) + 
                   (1-prob) * (total - i + total + 1),
                   2 + total)
    print enum
