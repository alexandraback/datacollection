import os, sys, math

inFile = None
outFile = None

mapping = {}

def can(sum, p):
	return math.ceil(sum/3.0) >= p

def canS(sum, p):
	if sum == 0:
		return p == 0

	if sum % 3 == 0 or sum %3 == 2:
		return math.ceil(sum/3.0) + 1 >= p
	return math.ceil(sum/3.0) >= p

def solveCase(caseNo):
	numbers = map(int, inFile.readline().strip().split(' '))
	(n,s,p) = numbers[:3]
	results = numbers[3:]

	D = []
	for x in range(n+1):
		D.append((s+1)*[0])

	for googler in range(1, n+1):
		for sup in range(0, s+1):
			r = D[googler-1][sup]
			if can(results[googler-1],p):
				r += 1
				if sup > 0:
					r = max(r, D[googler-1][sup-1])
			else:
				if canS(results[googler-1],p) and sup > 0:
					r = max(r, D[googler-1][sup-1] + 1)

			D[googler][sup] = r

	ans = D[n][s]

	outFile.write("Case #{0}: {1}\n".format(caseNo, ans))

def main():
	t = int(inFile.readline().strip())
	for i in xrange(t):
		solveCase(i+1)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()