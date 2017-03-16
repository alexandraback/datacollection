import sys
sys.setrecursionlimit(10001)

def columns(A):
	R = len(A)
	C = len(A[0])
	return [[A[r][c] for r in xrange(R)] for c in xrange(C)]

def valid(R, C):
	for i in xrange(n):
		for j in xrange(m):
			if all(x <= R[i][j] for x in R[i]):
				continue
			elif all(x <= R[i][j] for x in C[j]):
				continue
			return False
	return True

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	n, m = map(int, sys.stdin.readline().strip().split())
	A = []
	for _ in xrange(n):
		A.append(map(int, sys.stdin.readline().strip().split()))
	print "Case #{}: {}".format(t, "YES" if valid(A, columns(A)) else "NO")
