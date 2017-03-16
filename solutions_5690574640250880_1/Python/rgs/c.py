#!/usr/bin/env python

def solve(r, c, m):
	#print 'solve', r, c, m

	def rotate(board):
		return [map(lambda row: row[col], board) for col in range(len(board[0]))] if board else []

	def solve_rec(r, c, m):
		#print "solve_rec", r, c, m
		if c == 1:
			b = min(m, r-1)
			return m - b, ([['.'] for _ in range(r-b)]) + ([['*']] * b)

		if r < c:
			m_left, board = solve_rec(c, r, m)
			# print 'invert', rotate(board)
			return m_left, rotate(board)

		if m == 0:
			m_left, board = solve_rec(r-1, c, m)
			# print 'm=0', board
			return m_left, board + [['.' for _ in range(c)]]

		# r >= c

		# r == 2 -> square 2x2
		if r == 2:
			if m == 3:
				return 0, [['.', '*'], ['*', '*']]
			else:
				return m, [['.', '.'], ['.', '.']]

		if m >= c:
			m_left, board = solve_rec(r-1, c, m-c)
			return m_left, board + [['*'] * c]
		else:
			b = min(m, c-2)
			m_left, board = solve_rec(r-1, c, m-b)
			return m_left, board + [(['.' for _ in range(c-b)]) + (['*'] * b)]

	m_left, board = solve_rec(r, c, m)
	board[0][0] = 'c'

	return None if m_left else board


t = input()
for ti in xrange(t):
	r, c, m = map(int, raw_input().split())

	ans = solve(r, c, m)

	print 'Case #' + str(ti+1) + ":"
	if not ans:
		print 'Impossible'
	else:
		# print 'ans=', ans
		for row in ans:
			print ''.join(row)