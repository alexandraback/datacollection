t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	n = [s for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
	
	n = list(n[0])

	ans = [n[0]]
	maxAlpha = n[0]

	index = 1
	while index < len(n):
		if n[index] >= maxAlpha:
			ans.insert(0, n[index])
			maxAlpha = n[index]
		else:
			ans.append(n[index])
		index += 1

	print "Case #{}: {}".format(i, "".join(ans))
