def work(board):
	r_board = []
	for c in range(len(board[0])):
		r_board.append([row[c] for row in board])
	grids = []
	for r in range(len(board)):
		for c in range(len(board[0])):
			grids.append((board[r][c], r, c))
	grids.sort()
	for grid in grids:
		value, r, c = grid
		if not (max(board[r]) == value or max(r_board[c]) == value):
			return "NO"
	return "YES"

if __name__ == '__main__':
	tc = int(raw_input())
	for cc in range(tc):
		n, m = [int(x) for x in raw_input().split()]
		board = []
		for r in range(n):
			board.append([int(x) for x in raw_input().split()])
		print "Case #%d: %s" % (cc + 1, work(board))
