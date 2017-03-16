#!/usr/bin/python
import sys

fl = open(sys.argv[1])
LINE = iter(fl.read().split())


def next_token():
    return next(LINE)

def next_int():
    return int(next_token())

cases = next_int()
for case_number in range(1, cases + 1):
    n = next_int()

    if n == 0:
        print "Case #%s: INSOMNIA" % case_number
        continue

    dgts = set()
    i = 0
    while len(dgts) < 10:
        i += 1
        num = n * i

        while num > 0:
            dgts.add(num % 10)
            num /= 10

    print "Case #%s: %s" % (case_number, n * i)


