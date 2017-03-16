import sys
import string

def twoPaths(i, j, classes):
	if len(classes[i]) <= 1:
		return False
	npaths = 0
	stack = [x for x in classes[i]]
	while len(stack) > 0:
		next = stack.pop(0)
		if next == j:
			npaths = npaths + 1
		stack.extend([x for x in classes[next]])
	return npaths >= 2			

def solver(N, classes):
	if N <= 2:
		return "No"
	for i in xrange(1,N+1):
		for j in xrange(1,N+1):
			if twoPaths(i,j,classes):
				return "Yes"	
	return "No"
				
f = open("test.out", 'w')
cases = open("test.in", 'r').readlines()
T = int(cases[0])
j = 1
for i in xrange(T):
	N = int(cases[j]) # number of classes
	classes = {}
	c = 1
	for k in xrange(j+1, j+N+1):
		ine = map(int, cases[k].split())
		classes[c] = ine[1:]
		c = c + 1
	j = j + N + 1
	result = solver(N, classes)
	line = "Case #" + str(i+1) + ": " + str(result)
	print line
	f.write(line + "\n")
f.close()