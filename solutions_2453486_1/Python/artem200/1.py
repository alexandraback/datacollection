def Xwin(A, x, y):
	B = A
	if (x != -1):
		B[x][y] = 'X'
	for i in range(4):
		if (B[i][0] == B[i][1] == B[i][2] == B[i][3] == 'X'):
			return 1
		if (B[0][i] == B[1][i] == B[2][i] == B[3][i] == 'X'):
			return 1
	if (B[0][0] == B[1][1] == B[2][2] == B[3][3] == 'X'):
		return 1
	if (B[3][0] == B[2][1] == B[1][2] == B[0][3] == 'X'):
		return 1
	return 0	

def Owin(A, x, y):
	B = A
	if (x != -1):
		B[x][y] = 'O'
	for i in range(4):
		if (B[i][0] == B[i][1] == B[i][2] == B[i][3] == 'O'):
			return 1
		if (B[0][i] == B[1][i] == B[2][i] == B[3][i] == 'O'):
			return 1
	if (B[0][0] == B[1][1] == B[2][2] == B[3][3] == 'O'):
		return 1
	if (B[3][0] == B[2][1] == B[1][2] == B[0][3] == 'O'):
		return 1
	return 0	


n = int(input())

for i in range(n):
	A = []
	c = 0
	for j in range(4):
		S = input()
		K = []
		for u in S:
			if (u == '.'):
				c += 1
			K.append(u)
		A.append(K)
	x = -1
	y = -1
	for j in range(4):
		for k in range(4):
			if (A[j][k] == 'T'):
				x = j
				y = k	
	if (Xwin(A, x, y) == 1):
		print('Case #' + str(i + 1) + ': X won')
	elif (Owin(A, x, y) == 1):
		print ('Case #' + str(i + 1) + ': O won')
	elif (c == 0):
		print ('Case #' + str(i + 1) + ': Draw')
	else:
		print ('Case #' + str(i + 1) + ': Game has not completed')
	ZZ = input()