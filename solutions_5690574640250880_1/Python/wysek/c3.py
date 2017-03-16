IMPOSSIBLE="Impossible"

def solve():
	R, C, M = [int(x) for x in input().split()]
	cells = R*C
	if R == 1 or C == 1:
		if R == 1 and C == 1:
			return 'c'
		row = 'c' + ('.' * (cells-M-1)) + ('*'*M)
		if R == 1:
			return row
		elif C == 1:
			return '\n'.join(row)
	if R > 1 and C > 1:
		if M in [cells-2, cells-3]:
			return IMPOSSIBLE
	row = ['.']*C
	rows = [row[:] for x in range(R)]
	rows[0][0] = 'c'
	rows[0][1] = rows[1][0] = rows[1][1] = '.'
	result = lambda rows: '\n'.join([''.join(row) for row in rows])
	m = 0
	for rowI in range(R-1, 1, -1):
		if m == M: break
		for colI in range(C-1, 1, -1):
			if m == M: break
			rows[rowI][colI] = '*'
			m = m + 1
	for rowI in range(R-1, 2, -1):
		if m >= M: break
		rows[rowI][0] = rows[rowI][1] = '*'
		m = m + 2
	for colI in range(C-1, 2, -1):
		if m >= M: break
		rows[0][colI] = rows[1][colI] = '*'
		m = m + 2
	if m-1 == M and R>2 and C>2 and rows[2][2] == '*':
		rows[2][2] = '.'
		m = m - 1
	if m < M and R > 2:
		rows[2][0] = rows[2][1] = '*'
		m = m + 2
	if m < M and C > 2:
		rows[0][2] = rows[1][2] = '*'
		m = m + 2
	if m + 3 == M:
		rows[0][1] = rows[1][0] = rows[1][1] = '*'
		m = m + 3
	if m == M: return result(rows)
	return IMPOSSIBLE

def main():
	T = int(input())
	for t in range(1, T+1):
		print("Case #%d:" % t)
		print(solve())

if __name__ == '__main__':
	main()

