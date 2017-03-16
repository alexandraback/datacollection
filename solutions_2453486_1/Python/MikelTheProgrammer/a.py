from sys import stdin, stdout, argv

fin = open(argv[1]) if len(argv) > 1 else stdin
fout = open(argv[2]) if len(argv) > 2 else stdout

def won(mat, symbol):
	for j in xrange(4):
		if sum(mat[j][x] == symbol for x in xrange(4)) == 4 \
			or sum(mat[j][x] == symbol for x in xrange(4)) == 3 and 'T' in mat[j] \
			or sum(mat[y][j] == symbol for y in xrange(4)) == 4 \
			or sum(mat[y][j] == symbol for y in xrange(4)) == 3 and 'T' in [mat[y][j] for y in xrange(4)]:
				return True
	if sum(mat[j][j] == symbol for j in xrange(4)) == 3 and 'T' in [mat[j][j] for j in xrange(4)] \
		or sum(mat[j][j] == symbol for j in xrange(4)) == 4 \
		or sum(mat[j][3-j] == symbol for j in xrange(4)) == 3 and 'T' in [mat[j][3-j] for j in xrange(4)] \
		or sum(mat[j][3-j] == symbol for j in xrange(4)) == 4:
		return True
	return False

def draw(mat):
	if '.' not in [mat[y][x] for y in xrange(4) for x in xrange(4)]:
		return True

N = int(fin.readline())
for j in xrange(1, N + 1):
	mat = [list(fin.readline().strip()) for k in xrange(4)]
	fin.readline()
	if won(mat, 'X'):
		fout.write('Case #%d: X won\n' % j)
	elif won(mat, 'O'):
		fout.write('Case #%d: O won\n' % j)
	elif draw(mat):
		fout.write('Case #%d: Draw\n' % j)
	else:
		fout.write('Case #%d: Game has not completed\n' % j)


