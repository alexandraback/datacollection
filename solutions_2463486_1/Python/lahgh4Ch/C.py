import math

def isPalindrome(x):
	strx = str(x)
	i = 0
	for i in range(len(strx) / 2):
		if strx[i] != strx[-(i + 1)]:
			return False
	return True

def enumerateFairSquares(n):
	fairSquare = []
	for x in range(1, int(math.sqrt(n)) + 1):
		if isPalindrome(x) and isPalindrome(x**2):
			fairSquare.append(x**2)
	return fairSquare

T = int(raw_input())
lowerBound = []
upperBound = []
for t in range(T):
	line = raw_input()
	A, B = line.split(' ')
	A = int(A)
	B = int(B)
	lowerBound.append(A)
	upperBound.append(B)
fairSquare = enumerateFairSquares(max(upperBound))
for t in range(T):
	count = 0
	for i in fairSquare:
		if i < lowerBound[t]:
			continue
		if i > upperBound[t]:
			break
		count += 1
	print 'Case #' + str(t + 1) + ':', count
