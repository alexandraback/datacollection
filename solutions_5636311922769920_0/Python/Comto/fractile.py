T = int(input())
for t in range(T):
	K,C,S = tuple(map(int,input().split()))
	print("Case #"+str(t+1)+":"," ".join([str(x) for x in range(1,K+1)]))