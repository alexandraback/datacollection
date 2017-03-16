# coding=utf-8 *** gatopeich for Google Code Jam 2014

# Problem A. Part Elf
import datetime
import time
from fractions import Fraction

filename = 'A-small-attempt1'

import concurrent.futures
import numpy as np


def case_solve(case, PQ):
    print('Solving #%d: %s' % (case, PQ))
    return case, solve(PQ)


def solve(PQ):
    P, Q = PQ.numerator,PQ.denominator
    q = 0
    while Q > 1:
        if Q & 1: return "impossible"
        q += 1
        Q >>= 1
    p = 0
    while P > 1:
        p += 1
        P >>= 1
    assert q >= p
    return q-p


if __name__ == '__main__':

    next_line = open(filename + '.in').readline
    out = open(filename + '.out', 'w')

    def write(*line):
        print(*line, file=out)
        print(*line)

    T = int(next_line())
    print(T, "cases")

    tests = []
    for case in range(1, T + 1):
        P, Q = map(int, next_line().split('/'))
        assert 0 < P <= Q
        tests.append((case, Fraction(P, Q)))

    with concurrent.futures.ProcessPoolExecutor() as executor:
        T0 = time.monotonic()
        for solution in executor.map(case_solve, *zip(*tests)):
            write('Case #%d: %s' % solution)
            elapsed = datetime.timedelta(seconds=time.monotonic() - T0)
            case = solution[0]
            print('Time:', elapsed, ", ETA:", elapsed * (len(tests) - case) / case)

    out.close()
