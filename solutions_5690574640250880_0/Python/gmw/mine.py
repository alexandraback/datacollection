
def process(i, o):
	T = int(i.readline())
	for case_num in range(1, T + 1):
		R, C, M = map(int, i.readline().split())
		ans = solve(R, C, M)
		if ans is None:
			ans = solve(C, R, M)
			if ans is not None:
				ans = zip(*ans) # transpose
		if ans is None:
			o.write('Case #{}:\nImpossible\n'.format(case_num))
		else:
			o.write('Case #{}:\n'.format(case_num))
			for line in ans:
				for c in line:
					o.write(c)
				o.write('\n')
		ok = None
		if ans is not None:
			ok = soln_ok(R, C, M, ans)
			
		print 'Case #{}/{}: {}x{}={} vs {} gaps={} ok={}'.format(case_num, T, R, C, R*C, M, R*C-M, ok)
		if ans is None:
			print 'Impossible'
			ans = [['.'] * C for _ in range(R)]
		for line in ans:
			print ''.join(c for c in line)
		print
		if ok == False:
			raise Exception('shit')

def soln_ok(R, C, M, board):
	assert board[R - 1][C - 1] == 'c'

	unexplored = set([(R - 1, C - 1)])
	touched = [[board[r][c] == '*' for c in range(C)] for r in range(R)]
	assert sum(sum(board[r][c] == '*' for c in range(C)) for r in range(R)) == M
	while len(unexplored) > 0:
		sq = unexplored.pop()
		adj = 0
		for dr in (-1, 0, +1):
			for dc in (-1, 0, +1):
				nsq = (sq[0] + dr, sq[1] + dc)
				if nsq[0] < 0 or nsq[0] >= R:
					continue
				if nsq[1] < 0 or nsq[1] >= C:
					continue
				if board[nsq[0]][nsq[1]] == '*':
					adj += 1
		touched[sq[0]][sq[1]] = True
		if adj == 0:
			for dr in (-1, 0, +1):
				for dc in (-1, 0, +1):
					nsq = (sq[0] + dr, sq[1] + dc)
					if dr == 0 and dc == 0:
						continue
					if nsq[0] < 0 or nsq[0] >= R:
						continue
					if nsq[1] < 0 or nsq[1] >= C:
						continue
					if not touched[nsq[0]][nsq[1]]:
						unexplored.add(nsq)

	return all(all(touched[r]) for r in range(R))
	

def solve(R, C, M):
	board = [['*'] * C for _ in range(R)]
	gaps = R * C - M
	board[R - 1][C - 1] = 'c'

	# special case: single non-mine square, click it
	if R * C - M == 1:
		return board
		
	# special case: vertical single
	if C == 1:
		for r in range(R - gaps, R - 1):
			board[r][0] = '.'
		return board
		
	# special case: vertical double
	if C == 2:
		if gaps % 2 == 1:
			return None
		if gaps == 2:
			return None
		fill_count = gaps // 2
		for r in range(R - fill_count, R):
			board[r][0] = '.'
			board[r][1] = '.'
		board[R - 1][C - 1] = 'c'
		return board

	# special case: horz single
	if R == 1:
		for c in range(C - gaps, C - 1):
			board[0][c] = '.'
		return board

	# special case: horz double
	if R == 2:
		if gaps % 2 == 1:
			return None
		if gaps == 2:
			return None
		fill_count = gaps // 2
		for c in range(C - fill_count, C):
			board[0][c] = '.'
			board[1][c] = '.'
		board[R - 1][C - 1] = 'c'
		return board

	# postcondition: board is at least 2x3 or 3x2 or bigger
	cut = C - gaps // R
	assert 0 <= cut <= C
		
	if cut <= C - 2:
		for r in range(R):
			for c in range(cut, C):
				board[r][c] = '.'
		board[R - 1][C - 1] = 'c'
		rem = gaps - (C - cut) * R # remainder
		assert rem >= 0 and rem < R

		for r in range(R - rem, R):
			board[r][cut - 1] = '.'

		if rem == 1:
			if cut == C - 2:
				if 3 > R - 1:
					return None
				board[0][cut] = '*'
				board[0][cut + 1] = '*'
				board[R - 3][cut - 1] = '.'
				board[R - 2][cut - 1] = '.'
			else:
				board[0][cut] = '*'
				board[R - 2][cut - 1] = '.'
			
		return board

	else: # less than 2 columns worth
		if gaps < 4:
			return None

		fill_count = gaps // 2
		rem = gaps - fill_count * 2
		if rem == 1:
			fill_count -= 1
		rem = gaps - fill_count * 2
		assert rem in (0, 3)
		if rem > fill_count:
			return None
		for r in range(R - fill_count, R):
			for c in range(C - 2, C):
				board[r][c] = '.'

		for r in range(R - rem, R):
			board[r][C - 3] = '.'

		board[R - 1][C - 1] = 'c'
		return board

	raise Exception('not here')

def main():
	cyclename = 'C-small-3'
	with open('source\\{}.in'.format(cyclename), 'rb') as i:
		with open('source\\{}.out'.format(cyclename), 'wb') as o:
			process(i, o)
		

if __name__ == '__main__':
	main()
