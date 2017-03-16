def solve_lawn(inp, out):
	nrows,ncols = [int(i) for i in inp.readline().split(' ')]
	rows = range(nrows)
	cols = range(ncols)
	board = list()
	col_max = list()
	row_max = list()
	for r in rows:
		board.append( [int(i) for i in inp.readline().split(' ')] )
	for c in cols:
		col_max.append(max(board[r][c] for r in rows))
	for r in rows:
		row_max.append(max(board[r]))
	for r in rows:
		for c in cols:
			v = board[r][c]
			if (v < row_max[r]) and (v < col_max[c]):
				return "NO"
	return "YES"

def solve(inp, out):
	n = int(inp.readline())
	for i in xrange(1,n+1):
		res = solve_lawn(inp, out)
		out.write("Case #%d: %s\n" % (i, res))

def main():
	with open("B-large.in", "rt") as inp:
		with open("B-large.out", "wt") as out:
			solve(inp, out)

if __name__ == '__main__':
	main()
