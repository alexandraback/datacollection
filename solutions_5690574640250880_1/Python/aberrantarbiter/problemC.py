def mines_near(board,i,j):
	row = max(i-1, 0)
	col = max(j-1, 0)
	count = 0
	while row <= min(i+1,len(board)):
		col = max(j-1, 0)
		while col <= min(j+1,len(board[0])):
			count += 1 if board[row][col] == -1 else 0
			col += 1
		row += 1
	return count

def by_zero(board, i, j):
	row = max(i-1, 0)
	col = max(j-1, 0)
	count = 0
	while row <= min(i+1,len(board)):
		while col <= min(j+1,len(board[0])):
			if board[row][col] == 0:
				return True
			col += 1
		row += 1
	return False

def label_board(board):
	for i, row in enumerate(board):
		for j, x in enumerate(row):
			if x == -1:
				continue
			board[i][j] = mines_near(board,i,j)

def is_one_clickable(labeled_board):
	for i, row in enumerate(labeled_board):
		for j, x in enumerate(row):
			if x == -1:
				continue
			if not by_zero(labeled_board, i, j):
				return False
	return True





class Move:
	def __init__(self, r, c, board):
		self.row = r
		self.col = c
		self.filled = []
		self.size = 0
		self.update(board)

	def __repr__(self):
		return "Move(%d,%d,%s)" % (self.row, self.col, self.filled)

	def update(self, board):
		r = self.row
		c = self.col
		self.filled = []
		row = max(r-1, 0)
		count = 0
		while row < min(r+2,len(board)):
			col = max(c-1, 0)
			while col < min(c+2,len(board[0])):
				if board[row][col] == -1:
					self.filled.append((row,col))
				col += 1
			row += 1
		self.size = len(self.filled)

def pretty_board(board):
	s ='\n'.join([''.join(['.' if x == 0 else '*' for x in row]) for row in board])
	return 'c' + s[1:]


def solve(vars):
	R = int(vars[0])
	C = int(vars[1])
	M = int(vars[2])
	free_spaces = [R * C - M]
	if free_spaces[0] == 0:
		return 'Impossible'
	moves = []
	possible_moves = []
	explored_state = [[0 for __ in range(C)] for _ in range(R)]
	board = [[-1 for __ in range(C)] for _ in range(R)]
	def apply_move(move):
		explored_state[move.row][move.col] = 1
		for i,j in move.filled:
			board[i][j] = 0
			free_spaces[0] -= 1
		for i,j in move.filled:
			if explored_state[i][j] == 0:
				possible_moves.append(Move(i,j,board))
		for m in possible_moves:
			m.update(board)
	def undo_move(move):
		explored_state[move.row][move.col] = 2
		for i,j in move.filled:
			board[i][j] = -1
			free_spaces[0] += 1
	free_spaces[0] -= 1
	board[0][0] = 0
	possible_moves = [Move(0,0,board)]	
	while free_spaces[0] != 0 and len(possible_moves) > 0:
		#print "Free spaces are %d" % free_spaces[0]
		#print "Choices are %s" % possible_moves
		move = possible_moves.pop()
		if move.size > free_spaces[0]:
			if len(moves) == 0:
				break
			last_move = moves.pop()
			#print "Can't apply, back tracking"
			#print "Last time added %d" % last_move.size
			#print "Popping %d off" % (last_move.size - 1,)
			undo_move(last_move)
			possible_moves = [x for x in possible_moves if (x.row, x.col) not in last_move.filled]
			for m in possible_moves:
				m.update(board)
			#print "Choices now are %s" % possible_moves
			#print pretty_board(board)
		else:
			#print "Applying %s" % move.filled
			apply_move(move)
			moves.append(move)
			possible_moves = sorted([x for x in possible_moves if x.size > 0],key=lambda x: -x.size)
	if free_spaces[0] == 0:
		return pretty_board(board)
	else:
		return 'Impossible'




def main():
	with open('input.txt','r') as f:
		problems = int(f.readline())
		answers = []
		for i in xrange(problems):
			print i
			vars = f.readline().split(' ')
			answers.append("Case #%d:\n%s" % (i+1, solve(vars)))
		with open('output.txt','w') as fout:
			fout.write('\n'.join(answers))

def go():
	print solve([10,10,81])

if __name__ == "__main__":
	main()
	#go()