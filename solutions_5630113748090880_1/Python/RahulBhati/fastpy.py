for T in xrange(int(raw_input())):
	N = int(raw_input())
	l = [0] * (2509)
	
	for i in range(2*N - 1):
		h = map(int, raw_input().split())
		for j in h:
			l[j] = ((l[j] + 1)&1)
			
	out = "Case #" + str(T+1) + ":"
	for i in range(2501):
		if (l[i] == 1):
			out += (" " + str(i))
	
	print out