import sys

cases = sys.stdin.readline()
non = ['a','e','i','o','u']

for case in range(0,int(cases)):	
	s,L = [v for v in sys.stdin.readline().split()]
	L = int(L)
	res = 0
	ind = 0
	sum = 0
	K = []

	for c in s:
		if not c in non: sum += 1
		else: sum = 0
		if sum >= L:
			K.append(ind)
		ind += 1

	next = 0
	for i in range(0, len(s) - L + 1):
		while next<len(K)-1 and i+L-1>K[next]: next+=1
		if next<len(K) and K[next]-i>=L - 1:
			res += len(s) - K[next]
		

	print "Case #%d: %d" % (case+1, res)
