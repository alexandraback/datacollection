#!/usr/bin/env python

FILE_NAME_BASE = 'C-large'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 10000

# The brute force check is used to verify if there is really no solution if
# the fast search algorithm doesn't find one. However, it is impractically slow
# for large boards.
bruteForceCheck = False

def parse(inp):
	rows, cols, mines = (int(x) for x in inp.readline().split())
	return rows, cols, mines

def search(rows, cols, mines):
	# One-dimensional board.
	# These corner cases are not handled properly by the recursive search.
	if rows == 1:
		return ['c' + '.' * (cols - 1 - mines) + '*' * mines]
	if cols == 1:
		return ['c'] + ['.'] * (rows - 1 - mines) + ['*'] * mines

	def recurse(rowsLeft, maxWidth, minesLeft):
		if rowsLeft == 1:
			# Putting fewer mines on the top row than the row below it will
			# result in unrevealed empty cells.
			return [maxWidth] if minesLeft == maxWidth else None
		if minesLeft == 0:
			# All mines placed, keep top rows empty.
			return [0] * rowsLeft
		# We have a non-zero amount of mines to place in a field that has
		# a sufficient number of cells.

		if minesLeft >= maxWidth:
			# Try a row with the maximum number of mines.
			found = recurse(rowsLeft - 1, maxWidth, minesLeft - maxWidth)
			if found is not None:
				found.append(maxWidth)
				return found

		# Try a row with a smaller amount of mines.
		# Don't leave just one cell open, that prevents flooding.
		for width in xrange(min(minesLeft, maxWidth - 1, cols - 2) + 1):
			if rowsLeft * width >= minesLeft:
				found = recurse(rowsLeft - 1, width, minesLeft - width)
				if found is not None:
					found.append(width)
					return found

	widths = recurse(rows, cols, mines)
	if widths is None:
		return None

	board = [
			'.' * (cols - width) + '*' * width
			for width in widths
			]
	assert board[0][0] == '.'
	board[0] = 'c' + board[0][1 : ]
	return board

class SearchBoard(object):

	def __init__(self, rows, cols):
		self.counts = [[0] * (cols + 2) for _ in xrange(rows + 2)]
		self.mineCount = 0

	def addMine(self, row, col):
		counts = self.counts
		assert counts[row + 1][col + 1] < 10
		top = counts[row + 0]
		top[col + 0] += 1
		top[col + 1] += 1
		top[col + 2] += 1
		mid = counts[row + 1]
		mid[col + 0] += 1
		mid[col + 1] += 10
		mid[col + 2] += 1
		bot = counts[row + 2]
		bot[col + 0] += 1
		bot[col + 1] += 1
		bot[col + 2] += 1
		self.mineCount += 1

	def removeMine(self, row, col):
		counts = self.counts
		assert counts[row + 1][col + 1] >= 10
		top = counts[row + 0]
		top[col + 0] -= 1
		top[col + 1] -= 1
		top[col + 2] -= 1
		mid = counts[row + 1]
		mid[col + 0] -= 1
		mid[col + 1] -= 10
		mid[col + 2] -= 1
		bot = counts[row + 2]
		bot[col + 0] -= 1
		bot[col + 1] -= 1
		bot[col + 2] -= 1
		self.mineCount -= 1

	def checkConnected(self):
		counts = self.counts
		cols = len(counts[0]) - 2
		rows = len(counts) - 2

		# Pick a cell to click on. Any zero cell will do: if all zeroes are
		# connected, clicking on any zero will reveal them all.
		for rowIdx, row in enumerate(counts):
			if rowIdx == 0 or rowIdx > rows:
				continue
			try:
				colIdx = row.index(0, 1, -1)
			except ValueError:
				pass
			else:
				click = (rowIdx, colIdx)
				break
		else:
			return None

		revealed = set()
		def reveal(row, col):
			if 1 <= row <= rows and 1 <= col <= cols:
				pos = (row, col)
				if pos not in revealed:
					revealed.add(pos)
					count = counts[row][col]
					if count == 0:
						for dr in (-1, 0, 1):
							for dc in (-1, 0, 1):
								if dr != 0 or dc != 0:
									reveal(row + dr, col + dc)
					else:
						assert count < 10
		reveal(*click)
		numNonMines = rows * cols - self.mineCount
		if len(revealed) != numNonMines:
			assert len(revealed) < numNonMines
			return None

		# Construct a board in the solution syntax.
		board = [
				['.' if cell < 10 else '*' for cell in row[1 : -1]]
				for row in counts[1 : -1]
				]
		board[click[0] - 1][click[1] - 1] = 'c'
		return [''.join(row) for row in board]

def searchBruteForce(rows, cols, mines):
	searchBoard = SearchBoard(rows, cols)

	def searchRec(idx, remaining):
		if remaining == 0:
			return searchBoard.checkConnected()
		elif idx < remaining:
			return None
		else:
			pos = divmod(idx, cols)
			searchBoard.addMine(*pos)
			found = searchRec(idx - 1, remaining - 1)
			searchBoard.removeMine(*pos)
			if found is not None:
				return found
			return searchRec(idx - 1, remaining)

	return searchRec(rows * cols - 1, mines)

def solve(rows, cols, mines):
	# This is the only case where there are no zero-cells but there is a
	# solution. Handling it separately means the search functions don't have
	# to deal with clicking on nonzero-cells.
	if mines == rows * cols - 1:
		return '\nc' + '*' * (cols - 1) + ('\n' + '*' * cols) * (rows - 1)

	board = search(rows, cols, mines)
	if board is None and bruteForceCheck:
		board = searchBruteForce(rows, cols, mines)
		if board is None:
			print 'confirmed: no solution for %dx%d board, %d mines' \
					% (rows, cols, mines)
		else:
			print 'ERROR: missed solution for %dx%d board, %d mines:' \
					% (rows, cols, mines)
			for row in board:
				print row
			print
	if board is None:
		return '\n' + 'Impossible'

	# Perform sanity checks.
	assert len(board) == rows
	assert all(len(row) == cols for row in board)
	counts = { 'c': 0, '.': 0, '*': 0 }
	for row in board:
		for cell in row:
			counts[cell] += 1
	assert counts['c'] == 1
	assert counts['*'] == mines

	flowBoard = [
			['.' if cell == 'c' else cell for cell in row]
			for row in board
			]
	def countMinesOn(row, col):
		if 0 <= row < rows and 0 <= col < cols:
			return 1 if flowBoard[row][col] == '*' else 0
		else:
			return 0
	def countMinesNear(row, col):
		return sum(
			countMinesOn(row + dr, col + dc)
			for dr in (-1, 0, 1)
			for dc in (-1, 0, 1)
			)
	def reveal(row, col):
		if 0 <= row < rows and 0 <= col < cols:
			assert flowBoard[row][col] != '*'
			if flowBoard[row][col] == '.':
				count = countMinesNear(row, col)
				flowBoard[row][col] = str(count)
				if count == 0:
					for dr in (-1, 0, 1):
						for dc in (-1, 0, 1):
							reveal(row + dr, col + dc)
	clickRow, = [i for i, row in enumerate(board) if 'c' in row]
	clickCol = board[clickRow].index('c')
	reveal(clickRow, clickCol)
	assert all('.' not in row for row in flowBoard), flowBoard

	assert all(type(row) == str for row in board)
	return ''.join('\n' + ''.join(row) for row in board)

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	inp = open(FILE_NAME_BASE + '.in', 'r')
	numCases = int(inp.readline())
	if NUM_PROCESSES == 0:
		results = [
			solve(*parse(inp))
			for _ in range(numCases)
			]
	else:
		from multiprocessing import Pool
		pool = Pool(NUM_PROCESSES)
		results = [
			pool.apply_async(solve, parse(inp))
			for _ in range(numCases)
			]
	inp.close()
	out = open(FILE_NAME_BASE + '.out', 'w')
	for case, result in enumerate(results):
		value = result if NUM_PROCESSES == 0 else result.get()
		out.write('Case #%d: %s\n' % (case + 1, value))
		out.flush()
	out.close()

if __name__ == '__main__':
	main()
