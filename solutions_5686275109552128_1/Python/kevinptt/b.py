for casen in range(1, int(input())+1):
	n = input()
	arr = list(map(int, input().split()))
	maxn = max(arr)
	ans = maxn
	for pancake in range(1, maxn):
		tmp = pancake
		for i in arr:
			tmp += (i-1) // pancake
		if ans>tmp: ans = tmp

	print("Case #%d: %d" % (casen, ans))
