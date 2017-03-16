#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys


def Height(position):
    return 1 + (abs(position[0]) + abs(position[1])) / 2


def Count(height):
    if height < 0:
        return 0
    return height*(2*height - 1)



binomial_cache = [
    [1],
    [1, 1],
]
def binomial(n, k):
    while len(binomial_cache) <= n:
        ext = []
        x = 0
        for y in binomial_cache[-1]:
            ext.append(x + y)
            x = y
        ext.append(x)
        binomial_cache.append(ext)
        
    if k < 0 or k > n:
        return 0

    return binomial_cache[n][k]


def binomial_sum(n, k):
    result = 0
    for i in xrange(k + 1):
        result += binomial(n, i)
    return result
    


def Solve(n, position):
    if position[1] < 0:
        return 0.0
    if abs(position[0] + position[1]) % 2 == 1:
        return 0.0

    height = Height(position)
    count0 = Count(height-1)
    count1 = Count(height)

    if n >= count1:
        return 1.0
    if n <= count0:
        return 0.0
    if position[0] == 0:
        return 0.0

    m = n - count0
    k = position[1] + 1
#    print m, k, 2*(height - 1)

    if m >= 2*(height - 1) + k:
        return 1.0


#    print "position = {0}".format(position)
#    print "height = {0}".format(height)
#    print "n - count0 = {0}".format(n - count0)
#    print n - count0, position[1]

    return 1.0 - 1e-8 * ((10**8 * binomial_sum(m, k-1)) / (2**m))


def main():
    number_of_cases = int(sys.stdin.readline())
    for case in xrange(1, number_of_cases + 1):
        n, x, y = map(int, sys.stdin.readline().split())
        print "Case #{0}: {1:.8f}".format(case, Solve(n, (x, y)))


if __name__ == '__main__':
    main()

