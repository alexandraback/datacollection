with open('D-large.in') as f:
	cases = int(f.readline())

	for i in range(cases):
		N = int(f.readline())
		n = [float(x) for x in f.readline().split()]
		k = [float(x) for x in f.readline().split()]

		n.sort()
		k.sort()

		n1 = n; k1 = k; war = N
		l = N-1;
		# War
		for j in range(N-1,-1,-1):
			if (k[l] > n[j]):
				war -= 1
				l -= 1

		# D-war
		dwar = 0;
		l = 0;
		for j in range(N):
			if (n[j] > k[l]):
				dwar += 1
				l += 1

		print "Case #%d: %d %d" % (i+1, dwar, war)