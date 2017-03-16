t = int(input ())
for test in range(t):
	cnt = 0
	a, b, k = (int(x) for x in input().split(" "))
	for i in range(a):
		for j in range(b):
			if ((i & j) < k):
				cnt += 1
	print ("Case #%d: %d" % (test+1, cnt))