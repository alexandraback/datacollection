#!/usr/bin/env python

import sys

numTests = int(raw_input())

for test in xrange(numTests):
	print 'Case #{0}:'.format(test + 1),
	board = []
	for i in xrange(4):
		board.append(list(raw_input().strip()))
	try:
		raw_input()
	except EOFError:
		pass
	board2 = zip(*board)
	xWon = set(['X', 'T'])
	oWon = set(['O', 'T'])
	if any(set(line).issubset(xWon) for line in board) or \
	   any(set(line).issubset(xWon) for line in board2) or \
	   set(board[i][i] for i in xrange(len(board))).issubset(xWon) or \
	   set(board[i][len(board) - i - 1] for i in xrange(len(board))).issubset(xWon):
		print 'X won'
	elif any(set(line).issubset(oWon) for line in board) or \
	     any(set(line).issubset(oWon) for line in board2) or \
	     set(board[i][i] for i in xrange(len(board))).issubset(oWon) or \
	     set(board[i][len(board) - i - 1] for i in xrange(len(board))).issubset(oWon):
		print 'O won'
	elif any('.' in line for line in board):
		print 'Game has not completed'
	else:
		print 'Draw'
	"""print '[' + str(board[0]) + ','
	print ' ' + str(board[1]) + ','
	print ' ' + str(board[2]) + ','
	print ' ' + str(board[3]) + ']'
	print"""
