import sys
sys.setrecursionlimit(10001)

def columns(A):
	return ["".join([A[r][c] for r in xrange(4)]) for c in xrange(4)]

def diagonal1(M):
	D = []
	for i in xrange(4):
		D.append(M[i][i])
	return "".join(D)

def diagonal2(M):
	D = []
	for i in xrange(4):
		D.append(M[3-i][i])
	return "".join(D)

def won(R, C, char):
	for row in R:
		if row == char * 4:
			return True
	for col in C:
		if col == char * 4:
			return True
	if diagonal1(R) == char * 4:
		return True
	if diagonal2(R) == char * 4:
		return True
	return False

def replace(M, char):
	Mn = []
	for row in M:
		Mn.append(row.replace("T", char))
	return Mn

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	R = []
	spaces = 0
	for _ in xrange(4):
		R.append(sys.stdin.readline().strip())
		spaces += R[-1].count(".")
	sys.stdin.readline().strip() # empty line
	
	Rx = replace(R, "X")
	Cx = columns(Rx)
	wx = won(Rx, Cx, "X")
	
	Ro = replace(R, "O")
	Co = columns(Ro)
	wo = won(Ro, Co, "O")

	if wx:
		ans = "X won"
	elif wo:
		ans = "O won"
	elif spaces == 0:
		ans = "Draw"
	else:
		ans = "Game has not completed"

	print "Case #{}: {}".format(t, ans)
