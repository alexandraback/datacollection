from sys import stdin, stdout, argv

fin = open(argv[1]) if len(argv) > 1 else stdin
fout = open(argv[2]) if len(argv) > 2 else stdout

def max_mat(mat, w, h):
	max_rows = [max(mat[y]) for y in xrange(h)]
	max_cols = [max(mat[y][x] for y in xrange(h)) for x in xrange(w)]
	return max_rows, max_cols

def possible(mat, w, h):
	max_rows, max_cols = max_mat(mat, w, h)
	for y in xrange(h):
		for x in xrange(w):
			if max_rows[y] > mat[y][x] and max_cols[x] > mat[y][x]:
				return False
	return True




N = int(fin.readline())
for case in xrange(1, N + 1):
	h, w = map(int, fin.readline().split())
	mat = [map(int, fin.readline().split()) for y in xrange(h)]

	print 'Case #%d: %s' % (case, ['NO', 'YES'][int(possible(mat, w, h))])