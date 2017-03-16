#!/usr/bin/env python

import sys
import math

def get_divisor(number):
    i = 2
    max_divisor = math.sqrt(number)
    while i < max_divisor and i < 1000:
        if number % i == 0:
            return i
        i += 1
    return None

def get_solution(coin):
    result = []
    for base in range(2, 11):
        number = int(coin, base)
        divisor = get_divisor(number)
        if divisor == None:
            return None
        else:
            result.append(divisor)
    return result

with file(sys.argv[1]) as f:
    f.readline()
    N, J = map(int, f.readline().split())
    print "Case #1:"

    results = 0

    current = 0
    while results < J:
        coin_core = "{0:b}".format(current).zfill(N - 2)
        coin = "1%s1" % coin_core
        result = get_solution(coin)
        if result != None:
            results += 1
            print coin + " " + " ".join(map(str, result))
        current += 1


