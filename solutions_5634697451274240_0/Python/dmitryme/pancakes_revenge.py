#!/usr/bin/python
import sys

fl = open(sys.argv[1])

cases = int(fl.readline())

for case_number in range(1, cases + 1):
    stack = fl.readline()

    res = 0
    last_char = None
    for ch in stack.strip():
        if ch != last_char:
            last_char = ch
            res += 1

    if last_char == '+':
        res -= 1

    print 'Case #%s: %s' % (case_number, res)
