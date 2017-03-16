import math
import sys
sys.setrecursionlimit(10000)

import time

def mine(R, C, M, board, current, past):
	if len(current) + len(past) == M:
		return printBoard(R, C, M, board, current, past)
	if len(current) == 0:
		return "Impossible\n"
	for curNode in current:
		new = set()
		x = curNode[0] - 1
		y = curNode[1] - 1
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )
		x = curNode[0] - 1
		y = curNode[1]
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )
		x = curNode[0] - 1
		y = curNode[1] + 1
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )
		x = curNode[0]
		y = curNode[1] - 1
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )
		x = curNode[0]
		y = curNode[1] + 1
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )
		x = curNode[0] + 1
		y = curNode[1] - 1
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )
		x = curNode[0] + 1
		y = curNode[1]
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )
		x = curNode[0] + 1
		y = curNode[1] + 1
		if x >= 0 and x < R and y >= 0 and y < C and board[x][y] == 0:
			new.add( (x, y) )

		# promising
		if len(current) + len(past) + len(new) > M:
			continue

		# set
		past.add(curNode)
		current.remove(curNode)
		current |= new
		for newNode in new:
			board[newNode[0]][newNode[1]] = 1

		# recursive
		reVal = mine(R, C, M, board, current, past)
		if reVal != "Impossible\n":
			return reVal

		# recover
		past.remove(curNode)
		current.add(curNode)
		current -= new
		for newNode in new:
			board[newNode[0]][newNode[1]] = 0

	return "Impossible\n"

def printBoard(R, C, M, board, current, past):
	relValue = ''
	for row in board:
		for col in row:
			if col == 0:
				relValue += '*'
			elif col == 1:
				relValue += '.'
			else:
				relValue += 'c'
		relValue += '\n'
	return relValue

start_time = time.time()

# inFile = open("input.txt", "r")
inFile = open("C-small-attempt0.in", "r")
outFile = open("C.out", "w")
T = int(inFile.readline())

for i in range(T):
	R, C, M = inFile.readline().split()
	R = int(R)
	C = int(C)
	M = int(M)
	board = [[0] * C for x in range(R)]
	board[0][0] = 2
	current = set()
	current.add((0, 0))
	past = set()
	outFile.write( ("Case #%d: " % (i + 1)) + '\n')
	outFile.write(mine( R, C, R * C - M, board, current, past ))

print time.time() - start_time, "seconds"
	





# for line in File:
# 	f.append(line.split())
# for i in range(int(f[0][0])):
# 	name = f[i+1][0]
# 	n = int(f[i+1][1])
# 	print "Case #%d:" %(i+1), solve(name, n)