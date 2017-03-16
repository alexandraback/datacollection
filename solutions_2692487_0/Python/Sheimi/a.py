#!/usr/bin/env python
import math


def print_result(case_no, msg):
    print "Case #%d: %s" % (case_no, msg)


def compute(armin, mote):
    i = 0
    while 1:
        if armin > mote:
            return armin + mote, i
        i += 1
        armin = armin * 2 - 1


def run_case(case_no):
    armin, N = raw_input().split()
    armin = int(armin)
    motes = [int(mote) for mote in raw_input().split()]
    motes.sort()
    results = []
    result = len(motes)

    if armin == 1:
        print_result(case_no, str(result))
        return

    for mote in motes:
        if mote < armin:
            armin += mote
            result -= 1
            continue
        if mote < armin * 2 - 1:
            armin = armin * 2 - 1 + mote
            continue
        results.append(result)
        armin, r = compute(armin, mote)
        result = result - 1 + r
    results.append(result)
    results.sort()
    result = results[0]

    print_result(case_no, str(result))


if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
