def f(r,n):
    return n*(2*n - 1) + 2 * n * r

import sys

sys.stdin = open("A.in")
sys.stdout = open("A.out", "w")

N = int(input())

for test in range(N):
	R, T = map( int , input().split() )
	
	print("Case #%d: " % (test + 1), end = "")
	
	l = 0
	r = 10**10
	
	last = -1
	
	while l <= r:
		m = ( l + r ) // 2
		
		if f(R, m) > T:
			r = m - 1
		else:
			last = m
			l = m + 1
	
	print(last)
	
	#print(won)
	