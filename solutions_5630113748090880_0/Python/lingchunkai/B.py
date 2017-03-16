

T = int(raw_input())
for t in xrange(T):
	S = int(raw_input())
	L = dict()
	for s in xrange(2*S-1):
		x = map(int, raw_input().split())
		for xx in x:
			if not xx in L:
				L[xx] = 1;	
			else: 
				L[xx] += 1;

	ans = []
	# print L
	for k,v in L.iteritems():
		if (v % 2) == 1:
			ans.append(k)

	ans.sort()

	print "Case #" + str(int(t+1)) + ": " + " ".join(map(str, ans))