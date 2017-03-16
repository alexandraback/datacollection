#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser

all_bases = [2, 3, 4, 5, 6, 7, 8, 9, 10]

def convert(coin, base):
    num = 0
    power = 1
    for c in coin[::-1]:
        if c == "1":
            num += power
        power *= base
    return num

def check_result(coin, divisors):
    assert len(coin) in (16, 32)
    assert len(divisors) == len(all_bases)
    for base, divisor in zip(all_bases, divisors):
        num = convert(coin, base)
        assert num % divisor == 0, "coin {} (={}), base {}, divisor {}".format(
            coin,
            num,
            base,
            divisor
        )

def solve(n, j):
    divisors = [x+1 for x in all_bases]
    result = []
    for i in xrange(j):
        if n == 16:
            core = "{0:07b}".format(i)
        elif n == 32:
            core = "{0:015b}".format(i)
        else:
            assert False
        coin = "1" + "".join([c+c for c in core]) + "1"
        result.append((coin, divisors))
    return result

inputfile = FileParser()
T = inputfile.read_int()
for test in range(1, T+1):
    N, J = inputfile.read_integers()

    result = solve(N, J)

    print "Case #{}:".format(test)
    for coin, divisors in result:
        check_result(coin, divisors)
        print "{} {}".format(coin, " ".join([str(x) for x in divisors]))
