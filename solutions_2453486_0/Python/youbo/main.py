S = 4

def gao(line):
	if line.count('X') == 4 or line.count('X') == 3 and line.count('T') == 1:
		return "X won"
	elif line.count('O') == 4 or line.count('O') == 3 and line.count('T') == 1:
		return "O won"
	else:
		return None

def work(board):
	ret = ""
	for r in range(S):
		ret = gao(board[r])
		if ret:
			return ret
	for c in range(S):
		ret = gao(reduce(lambda x, y: x + y, [row[c] for row in board], ""))
		if ret:
			return ret
	ret = gao(reduce(lambda x, y: x + y, [board[i][i] for i in range(S)], ""))
	if ret:
		return ret
	ret = gao(reduce(lambda x, y: x + y, [board[i][S - 1 - i] for i in range(S)], ""))
	if ret:
		return ret
	return "Draw" if reduce(lambda x, y: x + y, board, "").count('.') == 0 else "Game has not completed"

if __name__ == '__main__':
	tc = int(raw_input())
	for cc in range(tc):
		board = []
		for i in range(S):
			board.append(raw_input())
		raw_input()
		print "Case #%d: %s" % (cc + 1, work(board))
