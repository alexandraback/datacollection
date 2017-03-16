def lowBit(x):
	assert x != 0
	x &= -x
	ret = 0
	while not(x & 1):
		ret += 1
		x >>= 1
	return ret

def highBit(x):
	assert x != 0
	ret = 0
	while x:
		ret += 1
		x >>= 1
	return ret-1

def normalize(board):
	while board[-1] == 0: board.pop()
	while board[0] == 0: board.pop(0)
	mn = min(lowBit(i) for i in board)
	for i in range(len(board)):
		board[i] >>= mn

def rotate(board):
	# require normalize first
	#print "Before"
	#print board
	mx = highBit(max(board))
	n = len(board)
	res = [0]*(mx+1)
	for i, val in enumerate(board):
		for j in range(mx+1):
			if val&(1<<j):
				res[j] |= (1<<(n-i-1))
	normalize(res)
	#print "After"
	#print res
	return res

def isEqual(a, b):
	return len(a) == len(b) and all(map(lambda x, y: x == y, a, b))

def isEqualR(a, b):
	if isEqual(a, b): return True
	for i in range(3):
		b = rotate(b)
		if isEqual(a, b): return True
	return False

dirs = [(1, 0), (0, -1), (-1, 0), (0, 1)]
cdir = {(1,0): (-1,0), (0,-1): (0,1), (-1,0): (1,0), (0,1): (0,-1)}

def make_bitmaps(x):
	# start from topest and leftest
	gres = [[] for i in range(x)]
	def re(curBoard, curx, cury, dir, rest_n):
		curBoards = [(rest_n, curBoard)]
		for dx, dy in dir:
			nBoards = []
			for rest, board in curBoards:
				nx, ny = curx + dx, cury + dy
				assert 0 <= nx < x+x and ny < x
				if ny < 0 or (ny == 0 and nx < x-1) or (board[ny] & (1<<nx)):
					continue
				# retry gen nboard 
				nboard = board[:]
				nboard[ny] |= 1 << nx
				# check for duplicate
				if any(map(lambda x: isEqual(x, nboard), gres[rest-1])):
					continue
				gres[rest-1].append(nboard)

				if rest-1 > 0:
					nBoards += [(rest-1, nboard)]
					nBoards += re(nboard, nx, ny, filter(lambda x: x != cdir[(dx, dy)], dirs), rest-1)
			curBoards += nBoards
		return curBoards

	bmp = [0] * x
	bmp[0] = 1 << (x-1)
	if x == 1:
		gres[0] = [bmp]
	else:
		re(bmp, x-1, 0, dirs, x-1)
	return gres[0]

def print_puzzle(puzzle):
	for i in puzzle:
		print bin(i)[-1:1:-1]

puzzles = [[]]*(6)
puzzle_sets = [{} for i in range(6)]
# build x <= 6
for i in range(1, 6+1):
	puzzles[i-1] = make_bitmaps(i)
	# normalize
	for b in puzzles[i-1]:
		normalize(b)
	
	# find symmetry
	for idx, board in enumerate(puzzles[i-1]):
		for idx2 in range(idx):
			if isEqualR(board, puzzles[i-1][idx2]):
				puzzle_sets[i-1][idx2] += [idx]
				break
		else:
			puzzle_sets[i-1][idx] = [idx]
#	print len(puzzle_sets[i-1])

for case_no in range(int(raw_input())):
	X, R, C = map(int, raw_input().split())
	if R > C: R, C = C, R
	if X >= 7:
		ans = True
	elif (R*C) % X != 0:
		ans = True
	else:
		ans = False
		# try all possible puzzle_sets
		#print puzzle_sets
		for key, sets in puzzle_sets[X-1].iteritems():
			n = len(puzzles[X-1][key])
			m = highBit(max(puzzles[X-1][key]))+1
			if n > m: n, m = m, n

			#print_puzzle(puzzles[X-1][key])

			# Quick judgement
			if m > C or n > R:
				#print "Boomb"
				ans = True
				break
			if m < C and n < R:
				#print "must ok"
				continue

			# find one puzzle in puzzle_sets fit
			for idx in sets:
				puzzle = puzzles[X-1][idx]
				n = len(puzzle)
				m = highBit(max(puzzle))+1

				if m > C or n > R:
					continue

				#print "R-n %d %d %d" % (R, n, R-n)
				#print "C-m %d %d %d" % (C, m, C-m)
				ok = False
				for cy in range(R-n+1):
					for cx in range(C-m+1):
						v = [[False]*C for i in range(R)]

						for i in range(n):
							x = puzzle[i]
							xidx = 0
							while x:
								if x&1:
									v[cy+i][cx+xidx] = True
								xidx += 1
								x >>= 1
						#print "V"
						#for i in range(n):
						#	print "".join(map(lambda x: "1" if x else "0", v[i]))
						#print ""
						def dfs(x, y):
							ret = 1
							assert not v[y][x]
							v[y][x] = True
							for dx, dy in dirs:
								nx, ny = x+dx, y+dy
								if 0 <= nx < C and 0 <= ny < R and not v[ny][nx]:
									ret += dfs(nx, ny)
							return ret
						for i in range(R):
							for j in range(C):
								if not v[i][j] and dfs(j, i) % X != 0:
									break
							else: continue
							break
						else:
							#print "Found at (%d, %d)" % (cx, cy)
							#print_puzzle(puzzle)
							break
					else: continue
					break # find one
				else: continue
				break
			else:
				ans = True
				break
	print "Case #%d: %s" % (case_no+1, "RICHARD" if ans else "GABRIEL")
