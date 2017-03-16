def victory(s):
	if '.' in s:
		return
	if 'X' in s and not 'O' in s:
		print('Case #%i: X won' % case)
		raise ZeroDivisionError
	if 'O' in s and not 'X' in s:
		print('Case #%i: O won' % case)
		raise ZeroDivisionError

def check():
	board = (input(), input(), input(), input())
	input()

	try:
		for i in range(4):
			s = board[i]

			victory(s)

		for i in range(4):
			s = []
			for j in range(4):
				s.append(board[j][i])

			victory(s)

		victory((board[0][0], board[1][1], board[2][2], board[3][3]))

		victory((board[0][3], board[1][2], board[2][1], board[3][0]))
	except ZeroDivisionError:
		return

	for row in board:
		for char in row:
			if char == '.':
				print('Case #%i: Game has not completed' % case)
				return
	else:
		print('Case #%i: Draw' % case)
		return

for i in range(1, int(input()) + 1):
	case = i
	check()