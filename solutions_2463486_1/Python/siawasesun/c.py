#!/usr/bin/env python

import sys

def is_palindrome(n):
    s = str(n)
    l = len(s)
    for i in range(l / 2):
        if s[i] != s[l - 1 - i]:
            return False
    return True;

def prepare():
    palindromes = []
    max_n = pow(10, 7)
    for i in range(max_n + 1):
        if is_palindrome(i):
            palindromes.append(i)
    return palindromes

def solve(A, B, palindromes):
    res = 0
    for p in palindromes:
        q = p * p
        if A <= q and q <= B:
            if is_palindrome(q):
                res += 1
    return res

test_cases = int(sys.stdin.readline())
palindromes = prepare()
for t in range(test_cases):
    A, B = [int(c) for c in sys.stdin.readline().split(" ")]
    print "Case #%d: %d" % (t + 1, solve(A, B, palindromes))
