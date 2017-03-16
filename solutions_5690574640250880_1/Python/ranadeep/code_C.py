import math

def transpose(A):
	if(isinstance(A,str)):
		return A
	else:
		col = len(A)
		row = len(A[0])
		B = [[A[c][r] for c in range(col)] for r in range(row)]
		return B

def pr(A):
	if(isinstance(A,str)):
		print(A)
	else:
		for row in A:
			print(''.join(row))

def func(r,c,k):
	if(r < c):
		return transpose(func(c,r,k))
	elif(k == c*r):
		A = [['.' for col in range(c)] for row in range(r)]
		A[0][0] = 'c'
		return A
	elif(k == 0): # r >= c
		return "Impossible"
	elif(k==1): # r >= c
		A = [['*' for col in range(c)] for row in range(r)]
		A[0][0] = 'c'
		return A
	elif(c==1): # r >=c and k > 1
		A = []
		for row in range(r):
			if row == 0: 
				t = 'c'
			elif row < k:
				t = '.'
			else:
				t = '*'
			A.append([t])
		return A
	elif(k < 4): # r >= c > 1 and k > 1
		return "Impossible"
	elif(c==2): # r >= c >= 2 and k >= 4
		if k%2:
			return "Impossible"
		else:
			A = []
			for row in range(r):
				if row < k//2:
					A.append(['.','.'])
				else:
					A.append(['*','*'])
			A[0][0] = 'c'
			return A
	else: # r >= c >= 3 and k >= 4 
		A = [['*' for col in range(c)] for row in range(r)]
		if(4 <= k <= 9): # r >= c >= 3 and k >= 4 
			for rw in range(2):
				for cl in range(2):
					A[rw][cl] = '.'
			if(k==5):
				return "Impossible"
			elif(k==6):
				A[0][2] = '.'
				A[1][2] = '.'
			elif(k==7):
				return "Impossible"
			elif(k==8 or k==9):
				for i in range(3):
					A[2][i] = '.'
					A[i][2] = '.'
				if(k==8):
					A[2][2] = '*'
		elif(c*c < k): # r >= c >= 3 and k > 9 (makes c > 3)
			for i in range(k//c):
				for j in range(c):
					A[i][j] = '.'
			if(k%c == 1):
				A[k//c][:2] = ['.']*2
				A[k//c-1][-1] = '*'
			else:
				A[k//c][:k%c] = ['.']*(k%c)
		else: # r >= c >= 4 and k > 9 and k <= c*c
			l = int(math.sqrt(k))
			for i in range(l):
				for j in range(l):
					A[i][j] = '.'
			rem = k - l*l
			if(rem == 1):
				A[l][:2] = ['.']*2
				A[l-1][l-1] = '*'
			elif(rem == l+1):
				A[l][0:rem-2] = ['.']*(rem-2)
				A[0][l] = '.'
				A[1][l] = '.'
				A[l][l-1] = '*'
			elif(rem < l):
				A[l][:rem] = ['.']*rem
			else:
				A[l][:l] = ['.']*(l)
				for i in range(rem-l):
					A[i][l] = '.'

		A[0][0] = 'c'
		return A


def takeInput():
	for e in range(int(input())):
		r, c, m = map(int,input().split())
		print("Case #{}:".format(e+1))
		pr(func(r,c,r*c-m))

takeInput()