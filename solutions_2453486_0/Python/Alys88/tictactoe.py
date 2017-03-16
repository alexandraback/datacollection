import sys


def boardPrint(board):
  """ displays the board (for debug only)
  """
  for line in board:
    print ("".join(line))
  print()


def answer(board):
	for player in ['X', 'O']:
		dots, col, line, diag1, diag2 = 0, 0, 0, 0, 0
		for i in range(4):
			if board[i][i] == player or board[i][i] == 'T':
				diag1 += 1
			if board[i][3-i] == player or board[i][3-i] == 'T':
				diag2 += 1
			col, line = 0, 0
			for j in range(4):
				if board[i][j] == player or board[i][j] == 'T':
					line += 1
				if board[j][i] == player or board[j][i] == 'T':
					col += 1
				if col == 4 or line == 4:
					return player + ' won'
				if dots == 0 and board[i][j] == '.':
					dots += 1
		if diag1 == 4 or diag2 == 4:
			return player + ' won'
	if dots > 0:
		return 'Game has not completed'
	return 'Draw'


def process(input, output):
  nb = int(input.readline().rstrip())
  for val in range(1, nb+1):
    print("Case ", val)
    board = []
    for i in range(4):
      board.append(list(input.readline().rstrip()))
    input.readline().rstrip() #blank line
    boardPrint(board)
    A = answer(board)
    print(A)
    output.write('Case #%d: %s\n' % (val,A))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("missing argument input_file")
        sys.exit(2)
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[1] + '.out', 'w+')
    process(input_file, output_file)
    input_file.close()
    output_file.close()
