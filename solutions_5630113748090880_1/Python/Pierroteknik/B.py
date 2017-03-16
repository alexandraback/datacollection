T = int(input())
for t in range(T):
	print("Case #" + str(t+1) + ": ",end="")
	height = []
	for i in range(2501):
		height.append(False)
	N = int(input())
	for i in range(2*N-1):
		line = list(map(int,input().split()))
		for h in line:
			height[h] = not(height[h])
	for i in range(2501):
		if (height[i]):
			print(i,end=" ")
	print("")