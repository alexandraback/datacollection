from __future__ import division
import math
import sys

def digits(x, base=10):
    d = []
    while x > 0:
        d.append(int(x % base))
        x = x // base
    d.reverse()
    return d

def from_digits(x):
    r = 0
    for i in x:
        r *= 10
        r += i
    return r

def is_palindrome(li):
    for x, y in zip(li, reversed(li)):
        if x != y:
            return False

    return True

def palindromes_below(x, base):
    """Return all palindromes who's primary half is below base^x"""
    p = base ** x
    for i in range(1, p):
        d = digits(i, 3)
        dr = list(reversed(d))
        yield from_digits(d + dr)
        yield from_digits(d + dr[1:])

def main():
    T = int(sys.stdin.readline().strip())

    cases = []
    for x in range(T):
        m, M = [int(x.strip()) for x in sys.stdin.readline().strip().split()]
        cases.append((m, M))

    answers = [9]
    gen = palindromes_below(8, 3)
    for x in gen:
        d = digits(x ** 2)
        if is_palindrome(d):
            answers.append(x**2)

    for i, (x, y) in enumerate(cases, 1):
        print "Case #%d: %d" % (i, sum(1 for a in answers if x <= a <= y))
        
if __name__ == "__main__":
    main()
