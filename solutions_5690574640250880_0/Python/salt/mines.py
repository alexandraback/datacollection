def pmatrix(R,C,matrix):
	for r in range(R):
		print ''.join(matrix[r])

def openCount(x,y,R,C,matrix):
	#print "x %d y %d" % (x,y)
	count = 0
	if x >= 0 and x < R and y >= 0 and y < C and matrix[x][y] == '.':
		for xx in range(-1,2):
			for yy in range(-1,2):
				if x+xx >= 0 and x+xx < R and y+yy >= 0 and y+yy < C:
					if matrix[x+xx][y+yy] == '*':
						count += 1				
	return count

def openOne(x,y,R,C,matrix):
	#print "x %d y %d" % (x,y)
	count = 0
	if x >= 0 and x < R and y >= 0 and y < C and matrix[x][y] == '.':
		for xx in range(-1,2):
			for yy in range(-1,2):
				if x+xx >= 0 and x+xx < R and y+yy >= 0 and y+yy < C:
					if matrix[x+xx][y+yy] == '*':
						count += 1
					matrix[x+xx][y+yy] = '.'
	return count


T = int(raw_input())
for t in range(T):
	(R,C,M) = raw_input().split(' ')
	R = int(R)
	C = int(C)
	M = int(M)
	matrix = [['*']*C for x in xrange(R)]
	step = 0
	line = 0
	pos  = 0
	mines = R*C-1
	matrix[0][0] = '.'

	while mines != M and line < max(R,C)+1:
		#print "pos %d line %d move %d" % (pos,line,(pos+1)/2)
		x = line+((pos+1)/2)*(pos%2)
		y = line+((pos+1)/2)*((pos+1)%2)
		if mines - openCount(x,y,R,C,matrix) >= M:
			mines -= openOne(x,y,R,C,matrix)
			#pmatrix(R,C,matrix)
		pos += 1
		if pos > max(R,C)*2-1:
			pos = 0
			line += 1
		#print '---------'
	matrix[0][0] = 'c'
	print "Case #%d:" % (t+1)
	if mines == M:
		pmatrix(R,C,matrix)
	else: 
		print "Impossible"