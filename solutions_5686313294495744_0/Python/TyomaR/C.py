for case in range(1, int(input()) + 1):
	n = int(input())
	arr = [input().split() for i in range(n)]
	mx = 0
	for mask in range(2 ** n):
		bad = False
		for i in range(n):
			if mask & (1 << i):
				found1 = False
				found2 = False
				for j in range(n):
					if arr[i][0] == arr[j][0] and (mask & (1 << j)) == 0:
						found1 = True
						break
				for j in range(n):
					if arr[i][1] == arr[j][1] and (mask & (1 << j)) == 0:
						found2 = True
						break
				if not found2 or not found1: 
					bad = True
					break
		if not bad:
			mx = max(mx, bin(mask).count('1'))
	print("Case #%d: %d" % (case, mx))