#!/usr/bin/python3

import operator

def subsets(s):
	if not s:
		yield 1
	else:
		for sub in subsets(s[1:]):
			yield sub
			yield s[0] * sub

def subtask(n, m, k):
	v = set(map(int, input().split()))

	for a1 in range(2, 6):
		for a2 in range(2, 6):
			for a3 in range(2, 6):
				s = [a1, a2, a3]
				prod = set(subsets(s))
				if v.issubset(prod):
					print('%d%d%d' % (a1, a2, a3))
					return

	print('WAT')

def task():
	r, n, m, k = map(int, input().split())
	for i in range(r):
		subtask(n, m, k)

for test in range(int(input())):
	print('Case #%d:' % (test + 1))
	task()
