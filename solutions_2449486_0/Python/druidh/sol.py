import sys

def read_ints():
	return map(int, sys.stdin.readline().split())
#	return [int(x) for x in sys.stdin.readline().split()]

def invertMatrix(mat):
	newMat = []
	for j in xrange(len(mat[0])):
		newMat.append([0]*len(mat))
	for i in xrange(len(mat)):
		for j in xrange(len(mat[i])):
			newMat[j][i] = mat[i][j]
	return newMat

(T,) = read_ints()
for case in range(1, T + 1):
	N, M = read_ints()
	field = []
	for i in xrange(N):
		field.append(read_ints())

	rows = []
	for row in field:
		rows.append(max(row))
	
	field_i = invertMatrix(field)
	cols = []
	for col in field_i:
		cols.append(max(col))


	ans = 'YES'
	for i in xrange(N):
		for j in xrange(M):
			if (min(rows[i], cols[j]) != field[i][j]):
				ans = 'NO'
				break
	print "Case #%d: %s" % (case, ans)
	

