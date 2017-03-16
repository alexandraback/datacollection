#!/usr/bin/python3

from sys import stdin
from itertools import takewhile, islice

def is_palindrome(x):
	return str(x) == str(x)[::-1]

def PalindromeGenerator(N):
	x = 1
	while x <= N:
		if is_palindrome(x):
			yield x
		x += 1

def GoodNumbersGenerator(N):
	for i in PalindromeGenerator(N):
		if i ** 2 >= N:
			break
		if is_palindrome(i ** 2):
			yield i ** 2

L = list(GoodNumbersGenerator(10 ** 14 + 2))

def count(x):
	return len(list(filter(lambda y: y <= x, L)))

T = int(stdin.readline())
for i in range(T):
	a, b = map(int, stdin.readline().split())
	print('Case #%d: %d' % (i + 1, count(b) - count(a - 1)))

