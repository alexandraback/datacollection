#!/usr/bin/env python2
import sys
from math import sqrt, ceil, floor

sys.setrecursionlimit(10000)

def squares(low, high):
    start = int(ceil(sqrt(low)))
    end = int(floor(sqrt(high))) + 1
    i = start
    while i < end:
        yield i
        i += 1


def palindrome(s):
    return not s or (s[0] == s[-1] and palindrome(s[1:-1]))


def main():
    num_cases = int(next(sys.stdin))
    for i in range(num_cases):
        low, high = [int(n) for n in next(sys.stdin)[:-1].split()]
        print "Case #%d: %d" % (i+1, sum(palindrome(str(s)) and palindrome(str(s**2)) for s in squares(low, high)))


if __name__ == '__main__':
    main()
