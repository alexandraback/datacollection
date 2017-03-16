import sys
import itertools
import math

sys.setrecursionlimit(10000)

def processLine(x):
	return x.split()
	'''x = x.split()
	a = []
	b = []
	for c in x[0]:
		if c == '?':
			a.append(c)
		else:
			a.append(int(c))
	for c in x[1]:
		if c == '?':
			b.append(c)
		else:
			b.append(int(c))
	return [a,b]'''

def makeCLarger(c,j):
	if len(c) == 0:
		return ['','']
	cs = []
	js = []
	for i in c:
		if i == '?':
			cs.append('9')
		else:
			cs.append(i)
	for i in j:
		if i == '?':
			js.append('0')
		else:
			js.append(i)
	return [''.join(cs), ''.join(js)]



def makeJLarger(c,j):
	if len(c) == 0:
		return ['','']
	cs = []
	js = []
	for i in c:
		if i == '?':
			cs.append('0')
		else:
			cs.append(i)
	for i in j:
		if i == '?':
			js.append('9')
		else:
			js.append(i)
	return [''.join(cs), ''.join(js)]

def increment(c):
	return chr(ord(c) + 1)

def decrement(c):
	return chr(ord(c) - 1)

def makeEqual(c,j):
	#print(c,j)
	if len(c) == 0:
		return ['','']
	if c[0] == '?' and j[0] == '?':
		poss = []
		poss.append(makeEqual(c[1:], j[1:]))
		for i in range(2):
			poss[0][i] = '0' + poss[0][i]
		poss.append(makeCLarger(c[1:], j[1:]))
		poss[1][0] = '0' + poss[1][0]
		poss[1][1] = '1' + poss[1][1]
		poss.append(makeJLarger(c[1:], j[1:]))
		poss[2][0] = '1' + poss[2][0]
		poss[2][1] = '0' + poss[2][1]
		#print(poss)
		return best(poss)
	if c[0] == '?':
		poss = []
		poss.append(makeEqual(c[1:], j[1:]))
		poss[0][0] = j[0] + poss[0][0]
		poss[0][1] = j[0] + poss[0][1]
		if j[0] < '9':
			poss.append(makeJLarger(c[1:], j[1:]))
			poss[1][0] = increment(j[0]) + poss[1][0]
			poss[1][1] = j[0] + poss[1][1]
		if j[0] > '0':
			poss.append(makeCLarger(c[1:], j[1:]))
			poss[-1][0] = decrement(j[0]) + poss[1][0]
			poss[-1][1] = j[0] + poss[1][1]
		return best(poss)
	if j[0] == '?':
		poss = []
		poss.append(makeEqual(c[1:], j[1:]))
		poss[0][0] = c[0] + poss[0][0]
		poss[0][1] = c[0] + poss[0][1]
		if c[0] < '9':
			poss.append(makeCLarger(c[1:], j[1:]))
			poss[1][1] = increment(c[0]) + poss[1][0]
			poss[1][0] = c[0] + poss[1][1]
		if c[0] > '0':
			poss.append(makeJLarger(c[1:], j[1:]))
			poss[-1][1] = decrement(c[0]) + poss[1][0]
			poss[-1][0] = c[0] + poss[1][1]
		return best(poss)
	if j[0] == c[0]:
		poss = makeEqual(c[1:], j[1:])
		poss[0] = c[0] + poss[0]
		poss[1] = j[0] + poss[1]
		return poss
	if c[0] < j[0]:
		poss = makeCLarger(c[1:], j[1:])
		poss[0] = c[0] + poss[0]
		poss[1] = j[0] + poss[1]
		return poss
	poss = makeJLarger(c[1:], j[1:])
	poss[0] = c[0] + poss[0]
	poss[1] = j[0] + poss[1]
	return poss

		
def f(x):
	c,j = processLine(x)
	#print(c,j)
	c,j = makeEqual(c,j)
	return c + ' ' + j



def criteria(c,j):
	#check diff
	s = []
	s.append(abs(int(c)-int(j)))
	s.append(c)
	s.append(j)
	return s

def best(x):
	cl = []
	jl = []
	for i in x:
		cl.append(i[0])
		jl.append(i[1])
	bestI = 0
	bestCriteria = criteria(cl[0],jl[0])
	for i in range(1,len(cl)):
		crit = criteria(cl[i], jl[i])
		if crit < bestCriteria:
			bestI = i
			bestCriteria = crit
	#print([cl[bestI], jl[bestI]])
	return [cl[bestI], jl[bestI]]

def best2(x):
	#print(x)
	return best(poss(*x))
	'''cl,jl = x
	bestI = 0
	bestCriteria = criteria(cl[0],jl[0])
	for i in range(1,len(cl)):
		crit = criteria(cl[i], jl[i])
		if crit < bestCriteria:
			bestI = i
			bestCriteria = crit
	#print([cl[bestI], jl[bestI]])
	return [cl[bestI], jl[bestI]]'''

def poss(c,j):
	poss = []
	for a in c:
		for b in j:
			poss.append([a,b])
	return poss 

def bruteForce(x):
	c,j = processLine(x)
	cList,jList = helper([''],[''],c,j)
	c,j = best2((cList,jList))
	return c + ' ' + j


digits = '0123456789'
def helper(cList, jList, c, j):
	#print(cList, jList)
	if len(c) == 0:
		return cList, jList
	nextC = []
	nextJ = []
	if c[0] == '?':
		for digit in digits:
			for i in cList:
				nextC.append(i + digit)
	else:
		for i in cList:
			nextC.append(i+c[0])
	if j[0] == '?':
		for digit in digits:
			for i in jList:
				nextJ.append(i+digit)
	else:
		for i in jList:
			nextJ.append(i+j[0])
	return helper(nextC,nextJ,c[1:],j[1:])







n = int(input())
for i in range(n):
	j = input()
	x = bruteForce(j)
	'''y = f(j)
	if x != y:
		print(j,x,y, sep = '     ')'''

	print("Case #{0}: {1}".format(i+1, x))