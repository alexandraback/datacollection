
def getstr(arr,R,C):
	ret = ""
	for x in range(0,R):
		for y in range(0,C):
			if (x == R-1 and y == C-1):
				ret = ret + "c"
				continue
			if (arr[x][y] == -1):
				ret = ret + "*"
			else:
				ret = ret + "."
		ret = ret+"\n"
	return ret

def nozero(arr,x,y):
	if arr[x][y] == 0:
		return False;
	if (x-1>0):
		if (y-1>0 and arr[x-1][y-1] == 0):
			return False
		if (arr[x-1][y] == 0):
			return False
		if (y+1<C and arr[x-1][y+1] == 0):
			return False
	if (y-1>0 and arr[x][y-1] == 0):
		return False
	if (y+1<C and arr[x][y+1] == 0):
		return False
	if (x+1<R):
		if (y-1>0 and arr[x+1][y-1] == 0):
			return False
		if (arr[x+1][y] == 0):
			return False
		if (y+1<C and arr[x+1][y+1] == 0):
			return False
	return True

def arrangemine(R,C,tr,M):
	tmparr = []
	for x in range(0,R):
		tmparr.append([])
		for y in range(0,C):
			tmparr[x].append(0)

	
	for y in range(0,C):
		for x in range(0,tr):
			if (M > 0):
				M -= 1
				tmparr[x][y]=-1
	if M > 0:
		for y in range(0,M):
			tmparr[tr][y] = -1
	return tmparr

def arrangeempty(R,C,tr,N):
	tmparr = []
	for x in range(0,R):
		tmparr.append([])
		for y in range(0,C):
			tmparr[x].append(-1)

	for y in range(0,C):
		for x in range(0,tr):
			if (N > 0):
				N -= 1
				tmparr[R-1-x][C-1-y]=0
	if N > 0:
		for y in range(0,N):
			tmparr[R-1-tr][C-1-y] = 0
	return tmparr

linearray = []
fp = open('./C-small-attempt1.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

op = open('./third.out','w')
T = int(linearray[0])
for i in range(0,T):
	line = linearray[i+1]
	splits = line.split()
	
	R = int(splits[0])
	C = int(splits[1])
	M = int(splits[2])

	"""arr = []
	for x in range(0,R):
		arr.append([])
		for y in range(0,C):
			arr[x].append(0)


	for k in range(0,M):
		arr[k/R][k%R] = -1"""
	if (M == R*C):
		op.write("Case #%s:\nImpossible\n" % (i+1))
		continue
	
	suc = False
	tr = R
	N = R*C - M
	p = 0
	while True:
		if (p == 0):
			if ((tr+1) * C < M):
				p += 1
				tr = R
				continue
			arr = arrangemine(R,C,tr,M)
		elif (p == 1):
			if ((tr+1) * C < N):
				break
			arr = arrangeempty(R,C,tr,N)

		if (M == R*C-1):
			suc = True
			op.write("Case #%s:\n%s" % (i+1,getstr(arr,R,C)))
			break

		for x in range(0,R):
			for y in range(0,C):
				if (arr[x][y] == 0):
					t = 0
					if (x-1>=0):
						if (y-1>=0 and arr[x-1][y-1] == -1):
							t += 1
						if (arr[x-1][y] == -1):
							t += 1
						if (y+1<C and arr[x-1][y+1] == -1):
							t += 1
					if (y-1>=0 and arr[x][y-1] == -1):
						t += 1
					if (y+1<C and arr[x][y+1] == -1):
						t += 1
					if (x+1<R):
						if (y-1>=0 and arr[x+1][y-1] == -1):
							t += 1
						if (arr[x+1][y] == -1):
							t += 1
						if (y+1<C and arr[x+1][y+1] == -1):
							t += 1
					arr[x][y] = t

		t = 0
		for x in range(0,R):
			for y in range(0,C):
				if (arr[x][y] != -1 and nozero(arr,x,y)):
					t += 1

		if (t == 0):
			suc = True
			op.write("Case #%s:\n%s" % (i+1,getstr(arr,R,C)))
			break
		tr -= 1
	if (not suc):
		op.write("Case #%s:\nImpossible\n" % (i+1))
op.close()