#!/usr/bin/env python2
# David Wahler <dwahler@gmail.com>
# Google Code Jam submission: "Fair and Square"

import sys, re, itertools, fractions
from collections import defaultdict, namedtuple
from math import *
from random import *
from bisect import *

def tokens():
    return raw_input().split()

def palindromes(max_digits):
    yield 0
    for digits in xrange(1, max_digits+1):
        suffix_digits = (digits+1) // 2
        odd_length = (digits % 2 == 1)

        for suffix in xrange(10**suffix_digits):
            suffix_str = str(suffix).rjust(suffix_digits, '0')
            if suffix_str[-1] == '0': continue

            prefix = ''.join(reversed(suffix_str))
            if odd_length: prefix = prefix[:-1]

            yield int(prefix+suffix_str)

def is_palindrome(num):
    s = str(num)
    return s == ''.join(reversed(s))

if __name__ == '__main__':
    T = int(*tokens())

    # precompute all values up to 10^14
    lookup = sorted(root*root for root in palindromes(7) if is_palindrome(root*root))

    for testCase in xrange(1, T+1):
        A, B = map(int, tokens())
        left = bisect_left(lookup, A)
        right = bisect_right(lookup, B)

        print "Case #%d:" % (testCase,),
        print right-left,
        print
