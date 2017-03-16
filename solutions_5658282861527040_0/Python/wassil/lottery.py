def solve(A,B,K):
	result = 0
	for i in range(A):
		for j in range(B):
			if i&j<K:
				result+=1 
	return result

for T in range(int(input())):
	A,B,K = map(int, input().split())
	print ("Case #"+str(T+1)+": "+str(solve(A,B,K)))