#!/usr/bin/python

import sys
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
    C, D, V = map(int, sin.readline().strip().split(" "))
    DENOMS = map(int, sin.readline().strip().split(" "))
    return dict(C=C, D=D, V=V, DENOMS=DENOMS)

def _run(CASE, C=None, D=None, V=None, DENOMS=None):
    CASE.r = 0

    v = set({})
    PRIMES = [1,2,3,5,7,11,13,17,19,23,29]

    for d in DENOMS:
        for x in list(v):
            n = 1
            while x + d * n <= V and n <= C:
                v.add(x + d * n)
                n += 1
        n = 1
        while d * n <= V and n <= C:
            v.add(d*n)
            n += 1
    for n in range(1, V+1):
        if n not in v:
            x = 1
            while n * x <= V and x <= C:
                for y in list(v):
                    g = 1
                    while y + n * g <= V and g <= C:
                        v.add(y + n * g)
                        g += 1
                v.add(n*x)
                x += 1
            CASE.r += 1
if __name__ == "__main__":
    main()
