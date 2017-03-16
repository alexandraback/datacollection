#!/usr/bin/env python2

import sys


def solve(array):
    items = []

    for line in array:
        for x in line:
            items.append(x)

    items = list(sorted(items))

    missing = []

    for v in set(items):
        if items.count(v) % 2:
            missing.append(v)

    return ' '.join(str(x) for x in sorted(missing))


count = int(sys.stdin.readline().strip())

current = 1

while current <= count:
    length = int(sys.stdin.readline().strip()) * 2
    array = []
    while length > 1:
        array.append([int(x) for x in sys.stdin.readline().strip().split(' ')])
        length -= 1
    print 'Case #{}: {}'.format(current, solve(array))
    current += 1
