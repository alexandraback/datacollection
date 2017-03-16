#!/usr/bin/python3

def gen():
	for size in range(1, 5):
		for i in range(10**(size - 1), 10**size):
			s = str(i)
			yield int(s + s[:-1][::-1])
		for i in range(10**(size - 1), 10**size):
			s = str(i)
			yield int(s + s[::-1])

def is_palin(n):
	s = str(n)
	return s == s[::-1]

r = []
for i in gen():
	sqr = i**2
	if is_palin(sqr):
		r.append(sqr)

def task():
	a, b = map(int, input().split())
	return sum(i >= a and i <= b for i in r)

for test in range(int(input())):
	print('Case #%d:' % (test + 1), task())
