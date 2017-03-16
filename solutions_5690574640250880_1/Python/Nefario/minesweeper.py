#!/usr/bin/python
import sys

def main():

	f = open(sys.argv[1], 'r')
	for lineNum, line in enumerate(f):
		line = line.rstrip('\n')
		if lineNum == 0:
			continue

		(r, c, m) = (int(n) for n in line.split(' '))
		print "Case #{}:".format(lineNum)
		analyze(r, c, m)


def analyze(r, c, m):
	# print "Row: {}, Col: {}, Mines: {}".format(r, c, m)
	totalCells = r*c
	totalEmptyCells = totalCells - m

	# Short Cut
	if totalEmptyCells == 0:
		print "Impossible"
		return
	elif totalEmptyCells == 1:
		game = 'c'
		for i in range(1, totalCells, 1):
			game += '*'
		printGame(game, c)
		return

	# Single Row game
	if r == 1 or c == 1:
		game = 'c'
		for i in range(1, totalCells, 1):
			if totalEmptyCells - game.count('.') > 1:
				game += '.'
			else:
				game += '*'
		printGame(game, c)
		return

	if totalEmptyCells == 4:
		reservedIndex = [1, c, c+1]
		game = 'c'
		for i in range(1, totalCells, 1):
			if i in reservedIndex:
				game += '.'
			else:
				game += '*'
		printGame(game, c)
		return

	if totalEmptyCells == 9 and r >= 3 and c >= 3:
		reservedIndex = [1, 2, c, c+1, c+2, 2*c, 2*c+1, 2*c+2]
		game = 'c'
		for i in range(1, totalCells, 1):
			if i in reservedIndex:
				game += '.'
			else:
				game += '*'
		printGame(game, c)
		return

	elif totalEmptyCells < 4 or totalEmptyCells in [5, 7]:
		print "Impossible"
		return

	# Mines fill nicely on columns
	if totalEmptyCells % c == 0:
		game = 'c'
		for i in range(1, totalEmptyCells, 1):
			game += '.'
		for j in range(len(game), totalCells, 1):
			game += '*'

		printGame(game, c)
		return
	if totalEmptyCells % r == 0:
		cols = (totalCells/r) - (totalEmptyCells/r)
		game = 'c'
		for i in range(1, totalCells, 1):
			if (i % c) + cols >= c:
				game += '*'
			else:
				game += '.'

		printGame(game, c)
		return

	# If it doesn't cause a single in a row/col
	if totalEmptyCells % c != 1 and totalEmptyCells/c > 1:
		game = 'c'
		for i in range(1, totalEmptyCells, 1):
			game += '.'
		for j in range(len(game), totalCells, 1):
			game += '*'
		printGame(game, c)
		return

	game = 'c'
	for length in range(c, 1, -1):
		rows = totalEmptyCells/length
		remainder = totalEmptyCells%length
		# print "Total Cells: {}, Length: {}, Rows: {}, Remainder: {}".format(totalEmptyCells, length, rows, remainder)
		if rows > 1 and remainder != 1:
			for i in range(0, rows, 1):
				for j in range(0, c, 1):
					# Preserve 'c'
					if i == 0 and j == 0:
						continue
					if j >= length:
						game += '*'
					else:
						game += '.'
			for i in range(0, remainder, 1):
				game += '.'
			for i in range(remainder, (r-rows)*c, 1):
				game += '*'
			# print "Rows: {}, Remainder: {}, Length: {}".format(rows, remainder, length)
			if len(game) == totalCells:
				printGame(game, c)
				return

	game = 'c'
	remaining = totalEmptyCells
	for length in range(c, 1, -1):
		rows = remaining/length
		remainder = remaining%length
		# print "B Total Cells: {}, Length: {}, Rows: {}, Remainder: {}".format(remaining, length, rows, remainder)
		if rows > 2 and remaining > length:
			for i in range(0, (rows-1), 1):
				for j in range(0, c, 1):
					# Preserve 'c'
					if i == 0 and j == 0:
						continue
					if j >= length:
						game += '*'
					else:
						game += '.'
			remaining -= length * (rows - 1)
			continue
		elif len(game) > 1 and remainder != 1:
			for i in range(0, rows, 1):
				for j in range(0, c, 1):
					if len(game) == 1 and j == 0:
						continue
					if j >= length:
						game += '*'
					else:
						game += '.'
			if remainder > 0:
				for i in range(0, remainder, 1):
					game += '.'
				for i in range(remainder, c, 1):
					game += '*'
			# Filling empty rows
			for i in range(0, ((r - len(game)/c) * c), 1):
				game += '*'
			# print "Rows: {}, Remainder: {}, Length: {}".format(rows, remainder, length)
			if len(game) != totalCells:
				print "Impossible"
				printGame(game, c)
				return
			else:
				printGame(game, c)
				return




	print "Impossible"

def printGame(gameString, column):
	game = [gameString[i:i+column] for i in range(0, len(gameString), column)]

	for row in game:
		print row

# def findAllAdjacent(r, c, m):


if __name__ == "__main__":
	main()