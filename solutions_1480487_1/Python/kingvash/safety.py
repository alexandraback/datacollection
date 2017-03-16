#!/usr/bin/env python

def solve(scores):
	N = scores[0]
	X = sum(scores[1:])

	ans = []
	for i in scores[1:]:
		low = 0.0
		high = 100.0
		while low + 10**-7 < high:
			test = (low + high) / 2.0

			p = test / 100.0

			s = i + X * test / 100.0
			for j in scores[1:]:
				# find amount of p needed to beat person
				if j < s:
					p += (s-j) / float(X)

			if p > (1 + test/100.0):
				high = test
			if p <= (1 + test/100.0):
				low = test

			print low, high, "\t", test, p

		ans.append(low)

	return " ".join(map(lambda x : str(round(x,7)), ans))




def solveFile(Filename):
	inFile = file(Filename, "r")
	outFile = file(Filename[:-2]+"out", "w")
	N = int(inFile.readline())
	for i, line in enumerate(inFile.readlines(),1):
		outFile.write("Case #%i: %s\n" %(i, solve([int(i) for i in line.split()])))

#print solve(1,0)
#print solve(1,1)
#print solve(4,0)
#print solve(4,47)

solveFile("test.in")
solveFile("A-small-attempt0.in")
solveFile("A-large.in")
