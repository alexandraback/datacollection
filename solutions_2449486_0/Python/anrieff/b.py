#!/usr/bin/python

def solve():
	n, m = map(int, raw_input().strip().split())
	a = []
	for i in xrange(n):
		a.append(map(int, raw_input().strip().split()))
	maxRow = [0] * n
	maxCol = [0] * m
	for i in xrange(n):
		for j in xrange(m):
			maxRow[i] = max(maxRow[i], a[i][j])
			maxCol[j] = max(maxCol[j], a[i][j])
	for i in xrange(n):
		for j in xrange(m):
			if a[i][j] < maxRow[i] and a[i][j] < maxCol[j]:
				return "NO"
	return "YES"
	

numTests = int(raw_input())
for tc in xrange(1, numTests + 1):
	print "Case #%d:" % tc, solve()
