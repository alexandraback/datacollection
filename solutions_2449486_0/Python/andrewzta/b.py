t = int(input())

for test in range(1, t + 1):
	n, m = [int(x) for x in input().split()]
	a = []
	for x in range(0, n):
		a += [[int(x) for x in input().split()]]
	
	maxr = []
	for i in range(0, n):
		r = 0
		for j in range(0, m):
			if a[i][j] > r:
				r = a[i][j]
		maxr += [r]

	maxc = [0] * m
	for i in range(0, n):
		for j in range(0, m):
			if a[i][j] > maxc[j]:
				maxc[j] = a[i][j]

	ok = True
	for i in range(0, n):
		for j in range(0, m):
			if (a[i][j] < maxr[i]) and (a[i][j] < maxc[j]):
				ok = False

	print("Case #" + str(test) + ": " + ("YES" if ok else "NO"))