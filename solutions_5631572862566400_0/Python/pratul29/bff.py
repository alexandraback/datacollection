tc = int(input())
for z in range(1, tc+1):
	inps = int(input())
	n = (input()).split()
	ans1 = "Case #" + str(z) + ": "
	n = list(map(int, n))
	push = n[0]
	ans = []
	while push not in ans:
		ans.append(push)
		prev = push
		push = n[push-1]
		if push in ans:
			for i in range( inps):
				if(n[i] == prev and i+1 not in ans):
					push = i+1;
	if 1 not in ans:
		ans.append(1)
	print(ans1 + str(len(ans)))
	
