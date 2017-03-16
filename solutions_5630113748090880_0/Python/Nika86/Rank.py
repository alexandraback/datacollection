#! /usr/bin/python

T = int(raw_input())

for t in range(1, T+1):

	N = int(raw_input())
	hCounts = {}

	for i in range(2*N - 1):
		curList = [int(inp) for inp in raw_input().split()]
		for h in curList:
			if h in hCounts:
				hCounts[h] += 1
			else:
				hCounts[h] = 1

	finalList = []

	for h in range(2600):
		if (h in hCounts) and (hCounts[h] % 2 != 0):
			finalList += [h]

	print 'Case #' + str(t) + ':',

	for h in finalList:
		print h,
	print