from math import *
fact = [0] + [ factorial(x + 1) / (2 * factorial(x - 1)) for x in xrange(1,9) ]
T = int(raw_input())
for t in xrange(1, T+1):
	a,b = map(int, raw_input().split(" "))
	ans = 0
	visited = [False] * (b+1)
	for i in xrange(a, b+1):
		if visited[i]:
			continue
		visited[i] = True
		n = str(i)
		tans = 0
		for j in xrange(len(n) - 1):
			m = int(n[j+1:] + n[:j+1])
			if a <= m <= b and not visited[m]:
				#print i, m
				tans += 1
				visited[m] = True
		ans += fact[tans]
	print "Case #%d: %d" %(t, ans)
