#!/usr/bin/env python

import sys
import string
import itertools
from pprint import pprint

with open('B-large.in', 'r') as f:
    lines = f.readlines()
    cc, lines = int(lines[0]), lines[1:]
    for c in xrange(cc):
        line = lines[c]
        numbers = map(int, line.split(' '))
        N, S, P = numbers[0], numbers[1], numbers[2]
        Ts = sorted(numbers[3:])
        answer = 0
        num_S = 0
        for t in Ts:
            if t > (3*P-3):
                answer += 1
            elif t >= (3*P-4) and t >= 2:
                num_S += 1
        answer += min(num_S, S)
        print "Case #%d: %d" % (c+1, answer)
