def badf(A,B,k):
	rt = 0
	for i in range(A):
		for j in range(B):
			if(i&j < k):
				rt += 1
	return rt

def takeInput():
	for t in range(int(input())):
		A,B,k = map(int,input().split())
		print("Case #{}: {}".format(t+1,badf(A,B,k)))

takeInput()