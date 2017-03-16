from math import sqrt,floor

def checkPrime(n):
	divLim = int(sqrt(n))
	divLim = min(divLim,10000) #;)
	if n & 1 == 0:
		return (2,False)
	for i in range(3,divLim+1,2):
		if n % i == 0:
			return (i,False)
	return (-1,True)

T = int(input())
N,J = tuple(map(int,input().split()))
cnt = 0
curNum = 1 << (N-2)
numLimit = 0
for i in range(N-1):
	numLimit |= 1 << i
divNum = [0]*11

print("Case #1:")
while cnt < J and curNum <= numLimit:
	isOK = True
	for i in range(2,11):
		dInt = int(bin(curNum)[2:]+"1",i)
		divNum[i],isPrime = checkPrime(dInt)
		if isPrime:
			isOK = False
			break
	if isOK:
		print(bin(curNum)[2:]+"1", " ".join([str(x) for x in divNum[2:]]))
		cnt += 1
	curNum += 1