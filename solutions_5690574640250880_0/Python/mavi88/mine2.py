
def fillGrid(grid,m,x,y,r,c,orientation):
	if m==0:
		return True
	if r==1 :
		for i in range(m):
			grid[x][i] = "*"
		return True
	if c==1 :
		for j in range(m):
			grid[j][y] = "*"
		return True
	if r==2 :
		n = r*c - m
		if n==1 or (n%2==0 and n>=4):
			k = m/2
			for i in range(k):
				grid[0][i] = "*"
				grid[1][i] = "*"
			if m%2==1:
				grid[0][k] = "*"
			return True
		else:
			return False
	if c==2 :
		n = r*c - m
		if n==1 or (n%2==0 and n>=4):
			k = m/2
			for i in range(k):
				grid[i][0] = "*"
				grid[i][1] = "*"
			if m%2==1:
				grid[k][0] = "*"
			return True
		else:
			return False
	if r-x == 3 and c-y == 3:
		if m==2 or m==4 or m==6 or m==7:
			return False
		if m>=1:
			grid[x][y] = "*"
		if m>=3:
			grid[x][y+1] = "*"
			grid[x][y+2] = "*"
		if m>=5:
			grid[x+1][y] = "*"
			grid[x+2][y] = "*"
		if m>=8:
			grid[x+1][y+1] = "*"
			grid[x+1][y+2] = "*"
			grid[x+2][y+1] = "*"
		return True
	if r-x == 3 and m<3:
		#print "rx",m,c-y
		for i in range(min(m,c-y-2)):
			grid[x][y+i] = "*"
		if m > c-y-2:
			grid[x+1][y]
		return True
	if c-y == 3 and m<3:
		#print "cy",m, r-x
		for i in range(min(m,r-x-2)):
			grid[x+i][y] = "*"
		if m > c-y-2:
			grid[x][y+1]
		return True
	mrc = min(r-x,c-y)
	if m < mrc :
		for i in range(min(m,c-y-2)):
			grid[x][y+i] = "*"
		if m > c-y-2:
			grid[x+1][y] = "*"
		return True
	if orientation == 1 : #and r-x> 3:		
		k = m/(c-y)
		if x+k > r-3:
			k = r-x-3
		#print "k",k
		for i in range(x,x+k):
			for j in range(y,c):
				grid[i][j] = "*"
		return fillGrid(grid,m-k*(c-y),x+k,y,r,c,0)
	elif True:#c-y >3:
		k = m/(r-x)
		if y+k > c-3:
			k = c-y-3
		#print "k",k
		for i in range(x,r):
			for j in range(y,y+k):
				grid[i][j] = "*"
		return fillGrid(grid,m-k*(r-x),x,y+k,r,c,1)
	#print "Other Case"
	#print "m = ",m
	#print "x,y =", x,y
	#print grid
	#return True

T = int(raw_input())

for t in range(T):
	r,c,m = map(int,raw_input().strip().split())
	grid = [["." for i in range(c)] for j in range(r)]
	possible = fillGrid(grid,m,0,0,r,c,1)
	print "Case #" + str(t+1) + ": "
	if possible:
		grid[r-1][c-1] = "c"
		for i in range(r):
			line = ""
			for j in range(c):
				line += grid[i][j]
			print line
	else:
		print "Impossible"
		