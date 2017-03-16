import os, sys

inFile = None
outFile = None

def printAnswer(case, answer):
	outFile.write('Case #{0}: {1}\n'.format(case+1, answer))

def solven1(c,v,A):
	ans = min(v, sum([a for (a,b) in A if b == c]))
	return ans

def solven2(c1, v1, c2, v2, A):
	ans = 0

	if c1==c2:
		ans = max(ans, solven1(c1, v1+v2, A))

	for k in range(0, len(A) + 1):
		ans = max(ans, solven1(c1,v1, A[0:k]) + solven1(c2,v2, A[k:]))

	return ans

def solven3(c1, v1, c2, v2, c3, v3, A):
	ans = 0

	ans = max(ans, solven2(c1, v1, c2, v2, A))
	ans = max(ans, solven2(c1, v1, c3, v3, A))
	ans = max(ans, solven2(c2, v2, c3, v3, A))

	if c1==c2 and c1==c3:
		ans = max(ans, solven1(c1, v1+v2+v3, A))

	for k in  range(0, len(A) + 1):
		for l in range(k, len(A) + 1):
			#print  A[0:k], ":::: ", A[k:l] ,"::::", A[l:]
			ans = max(ans, solven1(c1,v1, A[0:k]) + solven1(c2, v2, A[k:l]) + solven1(c3, v3, A[l:]))

	return ans

def solveCase(caseNo):
	(n,m) = map(int, inFile.readline().strip().split())
	low = map(int, inFile.readline().strip().split())
	high = map(int, inFile.readline().strip().split())

	A = [(high[i], high[i+1]) for i in range(2*m) if i%2==0]

	#print A

	ans = 0
	if n==1:
		ans = solven1(low[1], low[0], A)

	if n==2:
		ans = solven2(low[1], low[0], low[3], low[2], A)
	
	if n==3:
		ans = solven3(low[1], low[0], low[3], low[2], low[5], low[4], A)
		
	printAnswer(caseNo, ans)


def main():
	cases = int(inFile.readline().strip())
	for case in range(cases):
		solveCase(case)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()