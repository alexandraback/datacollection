from Queue import Queue

def Inside(n, m, x, y):
	return (x >= 0 and x < n and y >= 0 and y < m)

def Rotate(n, m, board):
	result = [[False for i in xrange(n)] for j in xrange(m)]
	for i in xrange(n):
		for j in xrange(m):
			result[j][i] = board[i][j]
	return result

def Compute(n, m, board):
	result = []

	for i in xrange(n):
		rowResult = []

		for j in xrange(m):
			res = 0
			for x in (i-1, i, i+1):
				for y in (j-1, j, j+1):
					if Inside(n, m, x, y) and ((x,y) != (i,j)) and board[x][y]:
						res += 1
			rowResult.append(res)

		result.append(rowResult)

	return result

def Verify(n, m, board, k, starting):
	if board is None:
		return False

	boardVal = Compute(n, m, board)
	(i, j) = starting

	if (board[i][j] == False) and (boardVal[i][j] == 0):
		q = Queue()
		q.put((i,j))
		visited = set([(i,j)])
		result = 0

		while not q.empty():
			(x, y) = q.get()
			result += 1

			if boardVal[x][y] == 0:
				for nx in (x-1, x, x+1):
					for ny in (y-1, y, y+1):
						if Inside(n, m, nx, ny) and ((nx,ny) != (x,y)) and (board[nx][ny] == False) and ((nx,ny) not in visited):
							q.put((nx, ny))
							visited.add((nx, ny))

		if result == n*m-k:
			return True
	
	if n*m-k == 1:
		return True

	return False

def Print(starting, T):
	if T is None: print "Impossible"
	else: 
		# print	"Possible"; return
		for i in xrange(len(T)):
			line = ""
			for j in xrange(len(T[i])):
				if starting == (i,j):
					line += "c"
				else:
					if T[i][j]: line += "*"
					else:	line += "."
			print line

def GenBoard(n, m, rows, k, numLast):
	T = [[True for i in xrange(m)] for j in xrange(n)]
	k = n*m - k
	pm = (k+rows-1) / rows
	last = (k - pm*(rows-numLast)) / numLast

	# print "k = %d, pm = %d, rows = %d, last = %d, numLast = %d" % (k, pm, rows, last, numLast)

	lf = None
	marked = 0

	for i in xrange(rows-numLast):
		for j in xrange(pm):
			T[i][j] = False
			lf = (i, j)
			marked += 1
	for i in xrange(rows-numLast, rows):
		for j in xrange(last):
			T[i][j] = False
			lf = (i, j)
			marked += 1
	for i in xrange(rows-numLast, rows):
		if marked < k:
			T[i][last] = False
			marked += 1

	starting = None

	if (lf[0] >= 1) and (lf[1] >= 1):	starting = (lf[0]-1, lf[1]-1)
	else: starting = (0, 0)

	return (starting, T)

def Solve():
	(n, m, k) = map(int, raw_input().split())
	# print "%d %d %d" % (n, m, k) ,
	
	if n == 1:
		T = [[False for i in xrange(m)]]
		for i in xrange(m-k, m):
			T[0][i] = True
		Print((0,0), T)
		return

	if m == 1:
		T = [[False] for i in xrange(n)]
		for i in xrange(n-k, n):
			T[i][0] = True
		Print((0,0), T)
		return

	else:
		if (n*m-k == 2) or (n*m-k == 3):
			# print "---------" ,
			pass
		else:
			kk = n*m - k
			minr = (kk+m-1) / m
			maxr = n
			for rows in xrange(minr, maxr+1):
				for numLast in xrange(1, rows):
					(starting, board) = GenBoard(n, m, rows, k, numLast)
					# print "XXXXXXXXXXXXXXXX"
					# Print(starting, board)
					# print "XXXXXXXXXXXXXXXX"
					if Verify(n, m, board, k, starting):
						Print(starting, board)
						return		

			(n, m) = (m, n)
			minr = (kk+m+1) / m
			maxr = n
			for rows in xrange(minr, maxr+1):
				for numLast in xrange(1, rows):
					(starting, board) = GenBoard(n, m, rows, k, numLast)
					if Verify(n, m, board, k, starting):
						board = Rotate(n, m, board)
						Print(starting, board)
						return

			
	Print(None, None)

if __name__ == '__main__':
	q = int(raw_input())
	# print q
	for i in xrange(1, q+1):
		print "Case #%d:" % (i)
		Solve()
