#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

testcase = input()

for q in xrange(testcase):

	line = raw_input().split(' ')
	N = int(line[0])
	M = int(line[1])


	#print ( N , M )
	board = []
	myboard = []
	ways = []
	for n in xrange(N) :
		b = []
		myb = []
		line = raw_input().split(' ')
		for m in xrange(M) :
			b.append( int(line[m]) )
			myb.append( 101 )
			ways.append( ( n, m, int(line[m]) ) )
		board.append(b)
		myboard.append(myb)

	for x in xrange( len(ways) ):
		for y in xrange( len(ways)-1 ):
			if ways[y][2] < ways[y+1][2] :
				temp = ways[y+1]
				ways[y+1] = ways[y]
				ways[y] = temp

	#print ways
	
	for way in ways :

		kareru = True
		n = way[0]
		h = way[2]
		for m in xrange(M) :
			if board[n][m] > h:
				kareru = False
				break
		if kareru :
			#print "YOKO KARU " + str(way)
			for m in xrange(M) :
				myboard[n][m] = h
			#print myboard

		kareru = True
		m = way[1]
		h = way[2]
		for n in xrange(N) :
			if board[n][m] > h:
				kareru = False
				break
		if kareru :
			#print "TATE KARU " + str(way)
			for n in xrange(N) :
				myboard[n][m] = h
			#print myboard

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
		sys.stderr.write("Case #" + str(q+1) + ": YES")
	else :
		print "Case #" + str(q+1) + ": NO"
		sys.stderr.write("Case #" + str(q+1) + ": NO")

	continue
