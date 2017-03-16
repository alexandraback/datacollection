import os, sys
from pprint import *

inFile = None
outFile = None

def printAnswer(case, answer):
	outFile.write('Case #{0}: {1}\n'.format(case+1, answer))


def winsLine(player, board, sx, sy, dx, dy):
	for x in range(4):
		# print (sx, sy)
		if board[sx][sy] not in [player, 'T']:
			return False

		sx += dx
		sy += dy



	return True

def wins(player, board):
	for x in range(4):
		if winsLine(player, board, 0, x, 1, 0):
			return True

		if winsLine(player, board, x, 0, 0, 1):
			return True

	if winsLine(player, board, 0, 0, 1, 1):
		return True

	if winsLine(player, board, 3, 0, -1, 1):
		return True

	return False
		

def solveCase(caseNo):
	ans = ''
	lines = []
	for line in range(5):
		lines.append(inFile.readline())


	board = [ x.strip() for x in lines[:4]]
	# print board
	winsX = wins('X', board)
	winsO = wins('O', board)

	if winsX:
		printAnswer(caseNo, 'X won')
		return

	if winsO:
		printAnswer(caseNo, 'O won')
		return

	completed = '.' not in ''.join(board)
	if completed:
		printAnswer(caseNo, 'Draw')
	else:
		printAnswer(caseNo, 'Game has not completed')

def main():
	cases = int(inFile.readline().strip())
	for case in range(cases):
		solveCase(case)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()