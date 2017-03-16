#!/usr/bin/python3

def task():
	e_max, r, n = map(int, input().split())
	v = list(map(int, input().split()))

	e = e_max
	gain = 0
	for i in range(n):
		e = min(e + r, e_max)

		found = False
		e_new = e_max
		for j in range(i + 1, n):
			e_new -= r
			if v[j] > v[i]:
				found = True
				break
		if not found:
			e_new = 0
		e_new = max(e_new, 0)

		d = e - e_new
		if d > 0:
			gain += v[i] * d
		e = min(e, e_new)

	return gain

for test in range(int(input())):
	print('Case #%d:' % (test + 1), task())
