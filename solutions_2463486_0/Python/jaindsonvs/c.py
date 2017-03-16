#!/usr/bin/env python
# -*- coding:utf-8 -*-

from math import sqrt

def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
        res = []
        for _ in xrange(N):
                res.append(foo())
        return res
def readlinearray(foo): return map(foo, raw_input().split())

def is_palindrome(n):
	n = str(n)
	return n == ''.join(reversed(n))
	
def is_square(n):
	return sqrt(n) == float(int(sqrt(n)))
	
def is_fair_and_square(n):
	return is_palindrome(n) and is_square(n) and is_palindrome(int(sqrt(n)))

def solve(A, B):
	ans = 0
	for i in xrange(A, B+1):
		if is_fair_and_square(i):
			ans += 1
	return ans

if __name__ == '__main__':
    C = readint()
    for c in xrange(1, C+1):
		A, B = readlinearray(int)
		ans = solve(A, B)
		print 'Case #%d: %s' % (c, ans)
