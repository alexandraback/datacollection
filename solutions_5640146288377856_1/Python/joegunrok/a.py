#!/usr/bin/python

import sys
import math

VERBOSE = True

sin = sys.stdin
line = lambda : sin.readline().strip()

class case(object):
    def __init__(self, number):
        self.number = number
        self.r = ""

    def __enter__(self):
        return self

    def __exit__(self, *arg):
        print "Case #%s: %s" % (self.number, self.r)


def parse_result(out):
    return out.readline().strip()


def main():
    TEST_CASES = int(line())
    for CASE_NUMBER in range(1, TEST_CASES+1):
        with case(CASE_NUMBER) as CASE:
            _run(CASE, **parse())


def parse():
    R, C, W = map(int, sin.readline().strip().split())
    return dict(R=R, C=C, W=W)


def _run(CASE, R=None, C=None, W=None):
    r = 0
    c = C
    while c:
        if c > W:
            if c % W != 0:
                c -= c % W
            else:
                c -= W
            r += 1
        elif R == 1:
            r += W
            c = 0
        else:
            r += 1
            c = C
            R -= 1
    CASE.r = r

if __name__ == "__main__":
    main()