
#data = [[2, 1, 2], [1, 1, 1], [2, 1, 2]]
def solve(data, N, M):
	rowh = [0]*N
	colh = [0]*M

	for r in range(0, N):
		for c in range(0, M):
			colh[c] = max(colh[c], data[r][c])
			rowh[r] = max(rowh[r], data[r][c])

	#print(rowh, colh)
	for r in range(0, N):
		for c in range(0, M):
			if data[r][c] < rowh[r] and data[r][c] < colh[c]:
				return "NO"

	return "YES"

with open('input.txt') as f:
	T = int(next(f))
	for curTest in range(1, T+1):
		N, M = map(int, next(f).split())
		data = [None] * N
		for r in range(0, N):
			data[r] = list(map(int, next(f).split()))

		#print(data, N, M)
		print("Case #%d: %s" % (curTest, solve(data, N, M)))


