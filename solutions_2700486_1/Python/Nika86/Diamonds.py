#! /Library/Frameworks/Python.framework/Versions/Current/bin/python

def Choose(nn,i):
	if (i > nn):
		return 0
	elif (i == 0):
		return 1
	else:
		return ((Choose(nn,i-1) * (nn-i+1)) / i)

def SumBinom(nn,i):
	
	ans = 0
	for j in range(i):
		ans += Choose(nn,j)

	ans = ans * 1.0
	for j in range(nn):
		ans /= 2.0

	return ans

T = int(raw_input())

for t in range(1,T+1):

	inpArr = raw_input().split()

	N = int(inpArr[0])
	X = int(inpArr[1])
	Y = int(inpArr[2])

	X = abs(X)

	for m in range(1000):
		if ((m + 1)*(2*m + 1) > N):
			break

	Nb = m * (2*m - 1)
	k = N - Nb
	n = 2*m

	if X+Y < n:
		ans = 1.0
	elif X+Y > n:
		ans = 0.0
	else:
		if Y >= n:
			ans = 0.0
		elif k >= n + Y + 1:
			ans = 1.0
		elif k < Y + 1:
			ans = 0.0
		else:
			ans = 1.0 - SumBinom(k,Y+1)

	print 'Case #'+str(t)+': '+str(ans)
