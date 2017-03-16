#!/usr/bin/env python

import numpy
import numpy.linalg

nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
uniq = {'Z': 0, 'W': 2, 'U': 4, 'X': 6, 'G': 8}

matrix = [[0 for i in range(10)] for j in range(10)]
chars = []

for index, num in enumerate(nums):
    for c in num:
        if c not in chars and c not in uniq:
            chars.append(c)
        if c in chars:
            matrix[chars.index(c)][index] += 1

N = input()

for n in range(N):
    line = raw_input()

    res = [0 for i in range(10)]
    for c in uniq:
        nl = line.replace(c, '')
        diff = len(line) - len(nl)
        res[uniq[c]] += diff

        for d in nums[uniq[c]]:
            line = line.replace(d, '', diff)

    target = [0 for i in range(10)]
    for c in line:
        target[chars.index(c)] += 1

    sl = numpy.linalg.solve(numpy.array(matrix), numpy.array(target))
    for i in range(10):
        res[i] += int(round(sl[i]))

    print 'Case #%d: %s' % (n + 1, ''.join(map(lambda (i, x): str(i) * x, enumerate(res))))
