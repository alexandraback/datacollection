import os, sys, math

inFile = None
outFile = None

def cycled(n, A, B):
	asStr = repr(n)
	sum = 0
	used = []
	s = len(asStr)
	for x in range(0,s):
		new = asStr[x:] + asStr[:x] 

		if new[0] == '0':
			continue
		
		new = int(new)
		if new > n and new <= B and not (new in used):
			used.append(new)
			sum += 1

	return sum

def solveCase(caseNo):
	print caseNo
	(A, B) = map(int, inFile.readline().strip().split(' '))
	ans = 0

	for x in range(A, B+1):
		ans += cycled(x, A, B)

	outFile.write("Case #{0}: {1}\n".format(caseNo, ans))

def main():
	t = int(inFile.readline().strip())
	for i in xrange(t):
		solveCase(i+1)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()