#!/usr/bin/python2

import sys
import math


def palindrome(n):
    n_str = str(n)
    return n_str == n_str[::-1]


def fair_and_square(n):
    if not palindrome(n):
        return False

    a = int(math.sqrt(n))
    if a * a != n:
        return False

    return palindrome(a)


def Solve():
    a, b = map(int, sys.stdin.readline().split())

    count = 0
    for n in xrange(a, b + 1):
        if fair_and_square(n):
            count += 1

    return count


num = int(sys.stdin.readline())

for case in range(1, num + 1):
    print "Case #%d: %d" % (case, Solve())
