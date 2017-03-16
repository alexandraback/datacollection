#!/usr/bin/env python

import sys
import multiprocessing

WUT = 10**16

def rvrsd(number):
    sn = str(number)
    s = int(''.join(reversed(sn)))
    if len(sn) == len(str(s)):
        return int(s)
    else:
        return WUT

assert rvrsd(23) == 32
assert rvrsd(6) == 6

def solve(i):
    seen = set([i])
    cnt = 0
    numbers = set([i])
    while True:
        cnt += 1
        new_numbers = set()
        for number in numbers:
            if number == 1:
                return cnt
            else:
                smaller = number - 1
                r = rvrsd(number)
                if smaller not in seen:
                    new_numbers.add(smaller)
                    seen.add(smaller)

                if r < number and r not in seen:
                    new_numbers.add(r)
                    seen.add(r)

        numbers = new_numbers

ifile = open(sys.argv[1])
cases = ifile.readline()
inputs = [int(i) for i in ifile]
pool = multiprocessing.Pool()
solutions = pool.map(solve, inputs)
for x, solution in enumerate(solutions):
    print "Case #{case}: {solution}".format(
        case=x + 1, 
        solution=solution
    )

    """
64
63 46
62 45 36 64?
61 44 35 63? 26 54? 63? 46?
"""
