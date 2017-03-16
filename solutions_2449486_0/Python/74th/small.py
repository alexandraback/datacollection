#!/usr/bin/env python
# -*- coding: utf-8 -*-

testcase = input()

for q in xrange(testcase):

	line = raw_input().split(' ')
	N = int(line[0])
	M = int(line[1])

	board = []
	myboard = []
	for n in xrange(N) :
		b = []
		myb = []
		line = raw_input().split(' ')
		for m in xrange(M) :
			b.append( int(line[m]) )
			myb.append( 2 )
		board.append(b)
		myboard.append(myb)

	for n in xrange(N):
		if board[n][0] == 1:
			kareru = True
			for m in xrange(M) :
				if board[n][m] != 1:
					kareru = False
					break
			if kareru :
				for m in xrange(M) :
					myboard[n][m] = 1

	for m in xrange(M):
		if board[0][m] == 1:
			kareru = True
			for n in xrange(N) :
				if board[n][m] != 1:
					kareru = False
					break
			if kareru :
				for n in xrange(N) :
					myboard[n][m] = 1
	
	yes = True
	for n in xrange(N):
		for m in xrange(M):
			if myboard[n][m] != board[n][m] :
				yes = False
				break
		if not yes :
			break
	
	if yes :
		print "Case #" + str(q+1) + ": YES"
	else :
		print "Case #" + str(q+1) + ": NO"

