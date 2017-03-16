T = int(raw_input())
for t in xrange(1, T+1):
	a,b = map(int, raw_input().split(" "))
	ans = 0
	dict = {}
	for i in xrange(a, b+1):
		n = str(i)
		for j in xrange(len(n) - 1):
			m = int(n[j+1:] + n[:j+1])
			if i < m <= b:
				if not (i,m) in dict:
					ans += 1
					dict[(i, m)] = True
	print "Case #%d: %d" %(t, ans)
