#!/usr/bin/env python

FILE_NAME_BASE = 'D-large'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	cells, rows, cols = (int(x) for x in inp.readline().split())
	return cells, rows, cols

possible = 'GABRIEL'
impossible = 'RICHARD'

def solve(cells, rows, cols):
	# Simplify code by ensuring rows >= cols.
	if rows < cols:
		rows, cols = cols, rows

	# If we have 7 or more cells, we can create pieces with holes in them.
	if cells >= 7:
		return impossible

	if (rows * cols) % cells != 0:
		# Grid doesn't fit an integer number of X-onimos.
		return impossible

	# Check whether there is a single piece that won't fit.
	for corner in xrange(1, (cells + 1) / 2 + 1):
		after = cells - corner + 1
		assert corner <= after, cells
		if corner > cols or after > rows:
			# L-shape won't fit.
			return impossible

	if cells <= 3:
		# No shapes are possible that would prevent filling the grid.
		return possible
	elif cells == 4:
		# 3x4 is always possible (checked manually).
		# Since the number of cells is a multiple of 4, we have two factors 2
		# in rows and cols. Any grid where either row or col is divisible by
		# 4 and the other is 3 or larger can be filled by adding 1x4 bars to
		# a 3x4 solution.
		# Grids where rows and cols each have one factor of two can be reduced
		# to grids where rows or cols is a multiple of 4 by adding 2x2 blocks
		# on one edge.
		# So all non-rejected grids larger than 3x4 are possible.
		# Grids with cols == 1 will have been rejected in the L-shape test.
		# So that leaves grids with cols == 2.
		if cols == 2:
			# The T- and Z-shaped pieces leave an odd amount of free cells
			# on either side, which cannot be filled with 4-cell pieces.
			return impossible
		else:
			return possible
	elif cells == 5:
		# Rows or cols must be a multiple of 5, so every large grid can be
		# reduced to 5x5 by padding with 1x5 bars.
		# 5x1 and 5x2 have already been rejected by L-shape test.
		assert cols >= 3, cols
		if cols == 3:
			# The W-shaped piece leaves 1 free cell on one side and 3 free cells
			# on the other side.
			return possible if rows >= 10 else impossible
		# The W-shaped piece doesn't block filling a 5x4 grid and I don't see
		# any way any of the other pieces would block it either.
		return possible
	elif cells == 6:
		# One side is a multiple of 6, or one is a multiple of 2 and the other
		# is a mulitple of 3.
		# Nx1 and Nx2 have already been rejected by L-shape test.
		assert cols >= 3, cols
		# Grids that cannot contain the 1x6 bar have been rejected already.
		assert rows >= 6, rows
		if cols == 3:
			# Cross-shaped piece leaves 2 free cells on one side and 4 on the
			# other side, which cannot be filled by 6-cell pieces in 3-wide
			# columns.
			return impossible
		# It would take too long to exhaustively investigate this, but I don't
		# see any way filling a grid this large could be blocked.
		return possible
	else:
		assert False

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
