import sys #from sys import * ???

def f(A,B,K):
	if A > B:
		A,B = B,A

	if K > A:
		return A*B
	
	w = K*A + K*B - K*K
	
	for i in range(K+1,A):
		for j in range(K, i):
			if i&j < K:
				w += 2

	for i in range(A,B):
		for j in range(K, A):
			if i&j < K:
				w += 1

	return w

T = int(sys.stdin.readline())

for tc in range(T):
	line = sys.stdin.readline()
	line = map(int, line.split())
	A = line[0]
	B = line[1]
	K = line[2]
	output = f(A,B,K)
	print "Case #" + str(tc + 1) + ": " + str(output)