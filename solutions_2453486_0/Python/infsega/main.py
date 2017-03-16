class Status:
	def __init__(self):
		self.x = True
		self.o = True
	
	def check(self, c):
		if c == '.':
			self.o = False
			self.x = False
		elif c == 'X':
			self.o = False
		elif c == 'O':
			self.x = False

def solve_game(inp, out):
	board = list()
	for i in range(4):
		board.append(inp.readline())
	incomplete = False
	for i in range(4):
		r = Status()
		c = Status()
		for j in range(4):
			if board[i][j] == '.':
				incomplete = True
			r.check(board[i][j])
			c.check(board[j][i])
		if r.x or c.x:
			return "X won"
		if r.o or c.o:
			return "O won"
	d1 = Status()
	d2 = Status()
	for i in range(4):
		d1.check(board[i][i])
		d2.check(board[i][3-i])
	if d1.x or d2.x:
		return "X won"
	if d1.o or d2.o:
		return "O won"
	if incomplete:
		return "Game has not completed"
	else:
		return "Draw"

def solve(inp, out):
	n = int(inp.readline())
	for i in xrange(1,n+1):
		st = solve_game(inp, out)
		out.write("Case #%d: %s\n" % (i, st))
		inp.readline()

def main():
	with open("A-small-attempt0.in", "rt") as inp:
		with open("output.txt", "wt") as out:
			solve(inp, out)

if __name__ == '__main__':
	main()
