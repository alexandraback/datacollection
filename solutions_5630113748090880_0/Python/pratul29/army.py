tc = int(input())
for z in range(1, tc+1):
	n = int(input())
	heights = [0] * 2501
	ans1 = "Case #" + str(z) + ": "
	for j in range(2*n-1):
		line = input().split()
		line = list(map(int, line))
		for i in line:	
			heights[i]+=1
	ans2 = []
	for i in range(2501):
		if(heights[i] % 2 != 0):
			ans2.append(i)
		if(len(ans2) == n):
			break;
	ans2 = list(map(str, ans2))
	print(ans1 + ' '.join(ans2))
