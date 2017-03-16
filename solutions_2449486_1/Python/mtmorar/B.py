#!/usr/bin/env python

import sys

numTests = int(raw_input())

for test in xrange(numTests):
	print 'Case #{0}:'.format(test + 1),
	n, m = map(int, raw_input().split())
	#m = raw_input()
	#print repr(n), repr(m)
	board = []
	for i in xrange(n):
		board.append(map(int, raw_input().split()))
	rows = [max(row) for row in board]
	cols = [max(col) for col in zip(*board)]
	#print '[{0}]'.format(',\n '.join(map(str, board)))
	#print '\n'.join(map(str, rows))
	#print ' '.join(map(str, cols))
	possible = True
	for i in xrange(len(rows)):
		for j in xrange(len(cols)):
			if board[i][j] < rows[i] and board[i][j] < cols[j]:
				possible = False
				break
		if not possible:
			break
	if possible:
		print 'YES'
	else:
		print 'NO'
