from random import *

def getv(A,b):
	ans = 0
	for i in A:
		ans*=b
		ans += i
	return ans

def solve(tc):
	k,c,s = map(int,raw_input().split())

	m = (k+c-1)/c

	print "Case #%d:"%tc,

	if (s < m):
		print "IMPOSSIBLE"
		return

	Z = set()

	cur = 0

	while (cur < k):
		now = []
		for j in range(cur,cur+c):
			if (j < k):
				now.append(j)
			else:
				now.append(0)

		v = getv(now,k)

		print v+1,

		cur += c
	print


t = input()
for i in range(1,t+1):
	solve(i)