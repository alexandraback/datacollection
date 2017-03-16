T = int(raw_input())



for t in xrange(T):
	read = raw_input()
	a, b, k = read.split()
	a = int(a)
	b = int(b)
	k = int(k)

	count = 0
	for i in xrange(a):
		for j in xrange(b):
			if i&j < k:
				count += 1

	print "Case #" + str(t+1) + ": " + str(count)