from math import ceil
from math import sqrt

def isPalin(n):
	s = str(n)
	for i in range(len(s)//2):
		if s[i] != s[len(s)-i-1]:
			return False
	return True

def makePalin(n):
	s = str(n)
	palin = []
	for i in range((len(s)+1)//2):
		palin.append(int(s[i]))
	if (len(s) % 2 == 1):
		return (False, palin)
	else:
		return (True, palin)

def incPalin(palint):
	mid = palint[0]
	palin = palint[1]
	palin[len(palin)-1] += 1
	i=len(palin)-1
	while (palin[i] == 10):
		palin[i] = 0
		if i > 0:
			palin[i-1] += 1
			i -= 1
		elif mid:
			mid = False
			palin.insert(0,1)
		else:
			mid = True
			palin[i]=1
	return (mid,palin)

def convPalin(palint):
	palin = palint[1]
	mid = palint[0]
	num = 0
	for n in palin:
		num = (num * 10) + n
	i = len(palin)-1
	if not mid:
		i -= 1
	for j in range(i, -1, -1):
		num = (num * 10) + palin[j]
	return num

def solveIt(vmin, vmax):
	vmin = ceil(sqrt(vmin))
	vmax = int(sqrt(vmax))
	count = 0
	i=vmin
	while not isPalin(i):
		i += 1
	palin = makePalin(i)
	while i <= vmax:
		if isPalin(i**2):
			count += 1
		palin = incPalin(palin)
		i = convPalin(palin)
	return count

trials = int(input())
for i in range(1, trials+1):
	inp = input()
	arr = inp.split(" ")
	vmin = int(arr[0])
	vmax = int(arr[1])
	print ("Case #" + str(i) + ": " + str(solveIt(vmin, vmax)))
