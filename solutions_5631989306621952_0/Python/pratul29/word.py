tc = int(input())
for z in range(1, tc+1):
	ans1 = "Case #" + str(z) + ": "
	a = input()
	ans2 = a[0]
	leng = len(a)
	for i in a[1:]:
		if ans2[0] <= i:
			ans2 = i + ans2
		else:
			ans2 = ans2 + i 
	ans = ans1 + ans2
	print(ans)
