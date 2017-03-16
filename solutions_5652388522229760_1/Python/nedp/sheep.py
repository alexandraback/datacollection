#!/usr/bin/env python3

from math import log

def count(n):

    ALL_DIGITS = '1234567890'

    # Check if n is zero; if so, INSOMNIA
    if n == 0:
        return 'INSOMNIA'
    # Else, we're guaranteed to eventually see all digits.

    # Track which digits we've seen using a character set.
    missing = set(ALL_DIGITS)

    # Start with m = n, and then iterate. Each iteration:
    m = n
    while m > 0:
        # Remember the digits in m.
        remember_digits(missing, m)

        # Check if we've seen all digits yet.
        if not missing:
            return m

        # Add n to m.
        m += n

def remember_digits(missing, m):
    for digit in str(m):
        if digit in missing:
            missing.remove(digit)

def oracle(n):

    ALL_DIGITS = '1234567890'

    seen = [False for _ in range(10)]

    for i in range(1, 200):

        m = i * n
        while m > 0:
            d = int(m % 10)
            seen[d] = True
            m = (m-d) / 10

        did_see_all = True
        for value in seen:
            did_see_all &= value
        if did_see_all:
            return i * n

    return 'INSOMNIA'

if __name__ == '__main__':

    n_cases = int(input())
    for i in range(1, n_cases+1):
        n = int(input())
        assert(count(n) == oracle(n))
        print("Case #{}: {}".format(i, count(n)))
