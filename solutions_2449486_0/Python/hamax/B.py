#!/usr/bin/python3

def mow(lawn, p):
	for i in range(len(p)):
		h = max(p[i])
		lawn[i] = tuple(min(f, h) for f in lawn[i])

def task():
	n, m = map(int, input().split())
	p = [list(map(int, input().split())) for i in range(n)]
	lawn = [[100] * m for i in range(n)]

	# horizontal
	mow(lawn, p)

	# vertical
	lawn = list(zip(*lawn))
	p = list(zip(*p))
	mow(lawn, p)

	if lawn == p:
		return 'YES'
	return 'NO'

for test in range(int(input())):
	print('Case #%d:' % (test + 1), task())
