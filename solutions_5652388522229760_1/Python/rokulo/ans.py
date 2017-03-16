#!/usr/bin/python2.7

import sys

T = int(sys.stdin.readline())

for i in xrange(T):
    N      = int(sys.stdin.readline())
    digits = [False] * 10
    finish = False
    current = 0

    if N == 0:
        print "Case #{0}: INSOMNIA".format((i+1))
        continue

    while not finish:
        current += N
        tmp = current
        while tmp > 0:
            digits[tmp % 10] = True
            tmp /= 10
        finish = True
        for j in xrange(10):
            finish &= digits[j]

    print "Case #{0}: {1}".format((i+1), current)
    


