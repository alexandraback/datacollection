lines = open("B-large.in").readlines()

n = int(lines.pop(0))

def testMatrix(matrix, N, M):
	for x in range(0, M):
		row = max(matrix[j][x] for j in range(0, N))
		for y in range(0, N):
			e = matrix[y][x]
			col = max(matrix[y][j] for j in range(0, M))
			
			if not min(col, row) <= e:
				return "NO"
	
	return "YES"


			


for i in range(0, n):
	N, M = map(int, lines.pop(0).split())
	
	matrix = []
	for j in range(0, N):
		matrix.append(map(int, lines.pop(0).split()))

	print("Case #%s: %s" % (i + 1, testMatrix(matrix, N, M)))

