fname = "C-small-attempt0.in"
# fname = "C-large.in"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt","w")

r,c,m = (3,2,20)

def check(x,i,j):
	return (x & 1 << (i*(c+2)+j+1)) > 0
assert check(2,0,0)
assert check(4,0,1)
assert check(1<<(c+3),1,0)
def flip(x,i,j):
	return x ^ (1 << (i*(c+2)+j+1))
# assert flip(0,0,0) == (1<<(r+3))
sol = {}
def test(x):
	# a = [[int(check(x,i,j)) for j in range(c)] for i in range(r)]

	# for i in range(r):
	# 	print a[i]
	# print x
	y = x 
	y |= x << 1 
	y |= x >> 1 
	y |= x << (c+1) 
	y |= x << (c+2) 
	y |= x << (c+3) 
	y |= x >> (c+1)
	y |= x >> (c+2)
	y |= x >> (c+3)
	# print x
	t = sum([sum([1-int(check(y,i,j)) for j in range(c)]) for i in range(r)])
	if not (r,c,t) in sol:
		# a = [[1-int(check(y,i,j)) for j in range(c)] for i in range(r)]

		# for i in range(r):
		# 	print a[i]
		print r,c,t
		sol[(r,c,t)] = y
		# print "---"
def visit(x,i,j):
	if i<0 or i>=r or j<0 or j>=c:
		return
	if check(x,i,j):
		return
	x = flip(x,i,j)
	if not x in visited:
		test(x)
		visited[x] = True
		visit(x,i+1,j)
		visit(x,i-1,j)
		visit(x,i,j-1)
		visit(x,i,j+1)
for r in range(1,6):
	for c in range(1,6):
		visited = {}
		sol[(r,c,r*c-1)] = 0
		visit(0,0,0)
s = ".*c"
for test in range(int(fi.readline())):
	r,c,m = [int(x) for x in fi.readline().strip().split()]
	print >>fo, "Case #%d:"%(test+1)
	if (r,c,m) in sol:
		y = sol[(r,c,m)]
		a = [[1-int(check(y,i,j)) for j in range(c)] for i in range(r)]
		a[0][0] = 2
		for i in range(r):
			print >>fo, "".join([s[a[i][j]] for j in range(c)])
	else:
		print >>fo, "Impossible"
