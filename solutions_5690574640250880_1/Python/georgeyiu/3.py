from parser import parse, split

def helper(test):
	r,c,m = test
	r0 = r-1
	c0 = c-1
	mat = [[0 for i in range(c)] for j in range(r)]
	#print '========================================='
	#print r,c,m
	# print matrix(mat)
	# for row in mat:
		# print row
	#print '-------'
	# import pdb; pdb.set_trace()
	while True:
		# if m == 4:
			# import pdb; pdb.set_trace()
		if r0 < 2 and c0 < 2 and m > 0:
			if c0 == 1 and r0 == 0 and m == 1:
				mat[0][1] = 1
				return matrix(mat)
			elif c0 == 0 and r0 == 1 and m == 1:
				mat[1][0] = 1
				return matrix(mat)
			elif c0 == 1 and r0 == 1 and m == 3:
				mat[0][1] = 1
				mat[1][1] = 1
				mat[1][0] = 1
				return matrix(mat)
			return '\nImpossible'
		m0 = m
		if r0 > c0:
			if m >= c0+1:
				mat[r0] = [1]*c
				r0 -= 1
				m -= c0+1
		else:
			if m >= r0+1:
				for rowi in range(len(mat)):
					mat[rowi][c0] = 1
				c0 -= 1
				m -= r0+1
		if m == m0:
			break
	if m == 0:
		return matrix(mat)
	if m > (c0-1)*(r0-1):
		return '\nImpossible'
	for i in reversed(range(2,r0+1)):
		for j in reversed(range(2,c0+1)):
			mat[i][j] = 1
			m -= 1
			if m == 0:
				return matrix(mat)
	return '\nImpossible'

def matrix(mat):
	blah = []
	for row in mat:
		blah.append(['.' if x == 0 else '*' for x in row])
	blah[0][0] = 'c'
	return '\n{}'.format('\n'.join([''.join(x) for x in blah]))

# schema here
schema = [(),[split(int)]]

num_tests, tests = parse(schema)
for case,test in enumerate(tests):
	sol = helper(test)
	print 'Case #{}: {}'.format(case+1, sol)

000
000
000
