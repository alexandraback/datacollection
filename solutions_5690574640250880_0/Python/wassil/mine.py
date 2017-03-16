def solve(A,R,C,M):
	#print (M)
	#printArray(A,R,C)
	if M == 0:
		return check(A,R,C)
	ok = False
	posB = findEmptyB(A,R,C)
	posR = findEmptyR(A,R,C)	
	A[posB[0]][posB[1]] = "*"
	if solve(A,R,C,M-1):return True
	A[posB[0]][posB[1]] = "."
	A[posR[0]][posR[1]] = "*"
	if solve(A,R,C,M-1):return True	
	A[posR[0]][posR[1]] = "."
	return False

def findEmptyB(A,R,C):
	for i in range(R-1,-1,-1):
		for j in range(C-1,-1,-1):
			if A[i][j] == ".":
				return (i,j)
	return (0,0)
def findEmptyR(A,R,C):
	for j in range(C-1,-1,-1):
		for i in range(R-1,-1,-1):
			if A[i][j] == ".":
				return (i,j)
	return (0,0)
	
def check(A,R,C):
	B = [[A[i][j] for j in range(C)] for i in range(R)]
	stack = [(0,0) for i in range(R*C)]
	f = 0
	e = 1
	while f<e:
		pos = stack[f]
		f+=1
		bomb = 0
		for i in range(-1,2):
			for j in range(-1,2):
				if 0<=pos[0]+i<R and 0<=pos[1]+j<C:
					if A[pos[0]+i][pos[1]+j] == "*":
						bomb += 1
		B[pos[0]][pos[1]] = str(bomb)
		if bomb == 0:
			for i in range(-1,2):
				for j in range(-1,2):
					if 0<=pos[0]+i<R and 0<=pos[1]+j<C:
						if B[pos[0]+i][pos[1]+j] == ".":
							B[pos[0]+i][pos[1]+j] = " "
							stack[e] = (pos[0]+i,pos[1]+j)
							e+=1						
	for i in range(R):
		for j in range(C):
			if B[i][j]==".": 
				return False
	return True

def printArray(A,R,C):
	for i in range(R):
		s = ""
		for j in range(C):
			s+=A[i][j]
		print (s)


for T in range(int(input())):
	print ("Case #%d:" % (T+1))
	R,C,M = map(int, input().split())
	NM = R*C - M
	if C>1 and R>1 and (NM ==2 or NM ==3 or NM ==5 or NM ==7):
		print ("Impossible")	
		continue
	A = [["." for j in range(C)] for i in range(R)]
	if solve(A,R,C,M):
		A[0][0] = "c"
		printArray(A,R,C)
	else:
		print ("Impossible")
	