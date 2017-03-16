def gunc(U):
	l = 0
	for i in U:
		if not (l==0 and i==1):
			l += i
	return -l

def func(N,K):
	for i in range(len(N)):
		N[i] = (N[i],-1)
	for i in range(len(K)):
		K[i] = (K[i],1)
	U = N + K
	U.sort()
	for i in range(len(U)):
		U[i] = U[i][1]
	return (len(N)-gunc([-i for i in U]), gunc(U))

def takeInp():
	for t in range(int(input())):
		input()
		N = list(map(float,input().split()))
		K = list(map(float,input().split()))
		print("Case #{}: {} {}".format(t+1,*func(N,K)))

takeInp()