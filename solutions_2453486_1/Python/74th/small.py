#!/usr/bin/env python
# -*- coding: utf-8 -*-

testcase = input()

def yokoari(p,x) :
	if board[x][0] != p and board[x][0] != 'T' :
		return False
	if board[x][1] != p and board[x][1] != 'T' :
		return False
	if board[x][2] != p and board[x][2] != 'T' :
		return False
	if board[x][3] != p and board[x][3] != 'T' :
		return False
	return True

def tateari(p,y) :
	if board[0][y] != p and board[0][y] != 'T' :
		return False
	if board[1][y] != p and board[1][y] != 'T' :
		return False
	if board[2][y] != p and board[2][y] != 'T' :
		return False
	if board[3][y] != p and board[3][y] != 'T' :
		return False
	return True

def nanameari(p) :
	if board[0][0] != p and board[0][0] != 'T' :
		return False
	if board[1][1] != p and board[1][1] != 'T' :
		return False
	if board[2][2] != p and board[2][2] != 'T' :
		return False
	if board[3][3] != p and board[3][3] != 'T' :
		return False
	return True

def nanameari2(p) :
	if board[0][3] != p and board[0][3] != 'T' :
		return False
	if board[1][2] != p and board[1][2] != 'T' :
		return False
	if board[2][1] != p and board[2][1] != 'T' :
		return False
	if board[3][0] != p and board[3][0] != 'T' :
		return False
	return True

board = []
for n in xrange(4) :
	board.append(['.','.','.','.'])

for q in xrange(testcase) :

	clear = False

	for n in xrange(4) :
		line = raw_input()
		boardline = []
		for m in xrange(4) :
			board[n][m] = line[m]

	for n in xrange(4) :
		if yokoari('O',n) or tateari('O',n) or nanameari('O') or nanameari2('O'):
			print "Case #" + str(q+1) + ": O won"
			clear = True
			break
		if yokoari('X',n) or tateari('X',n) or nanameari('X') or nanameari2('X'):
			print "Case #" + str(q+1) + ": X won"
			clear = True
			break

	if not clear :
		for n in xrange(4) :
			for m in xrange(4) :
				if board[n][m] == '.' :
					clear = True
					print "Case #" + str(q+1) + ": Game has not completed"
					break
			if clear :
				break
	
	if not clear :
		print "Case #" + str(q+1) + ": Draw"

	if q != testcase -1 :
		d = raw_input()
