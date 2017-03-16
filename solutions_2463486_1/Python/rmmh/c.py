import sys
import random

#sys.stdin = open("C-small-attempt0.in")

n_cases = input()

def to_ints(s):
    return map(int, s.split())

def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

# precompute!

b = 10**14
palins = filter(is_palindrome, xrange(int(b ** .5) + 2))
squares = [x**2 for x in palins]
palin_squares = filter(is_palindrome, squares)

for case in xrange(1, n_cases + 1):
    a, b = to_ints(raw_input())

    out = sum(1 for x in palin_squares if a <= x <= b)

    #print a, b, palin_squares

    print "Case #%d: %s" % (case, out)
