#!/usr/bin/python

import sys
import fileinput
import string

input = fileinput.input()

T = int(input.next().strip())

for tcase in xrange(T):
    print 'Case #%d:' % (tcase + 1),
    n = int(input.next().strip())
    values = []
    for i in range(n):
        l, h = map(int, input.next().strip().split())
        values.append([l,h])
    values.sort(key=lambda x: x[1], reverse=True)

    played = 0
    score = 0
    while values:
        if values[-1][1] <= score:
            played += 1
            score += 2 if values[-1][0] >= 0 else 1
            values.pop()
            continue
        for lst in values:
            if lst[0] >= 0 and lst[0] <= score:
                played += 1
                score += 1
                lst[0] = -1
                break
        else:
            print 'Too Bad'
            break
    if not values:
        print played
