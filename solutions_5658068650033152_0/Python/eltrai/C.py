#!/usr/bin/python

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(N, M, K):
	if M < 3 or N < 3:
		return K
	ret = K
	for i in range(3, N+1):
		for j in range(3, M+1):
			req = 2*(i-2) + 2*(j-2)
			enclosed = (i-2)*(j-2)+req
			#print("Considering", i, j, "with enc", enclosed, "and total req", req)
			req += max(0, K - enclosed)
			#print("Final req", req)
			ret = min(ret, req)
	
	return ret

cases = readint()
for k in range(cases):
	N,M,K = readarray(int)
	print('Case #' + str(k+1) + ': ' + str(solve(N,M,K)))
