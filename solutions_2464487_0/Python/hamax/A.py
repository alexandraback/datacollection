#!/usr/bin/python3

def task():
	r, t = map(int, input().split())

	left = 1
	right = 707106780
	while right > left:
		n = (left + right + 1) // 2
		porab = n + 4 * ((n - 1) * n / 2) + 2 * r * n
		if porab <= t:
			left = n
		else:
			right = n - 1

	if left != right:
		raise Exception()

	return left

for test in range(int(input())):
	print('Case #%d:' % (test + 1), task())
