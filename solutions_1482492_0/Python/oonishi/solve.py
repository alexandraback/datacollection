# coding: shift-jis

from math import sqrt

def solve(X, T, D, A):
	N = len(X)
	x = 0.0
	t = 0.0
	ans = [0.0]*(N+1)
	ans[0] = sqrt(2*D/A)
	for i in range(N):
		if X[i] <= D:
			v = sqrt(2*X[i]*A)
			t = (sqrt(v**2 + 2*A*(D-X[i])) - v)/A
			ans[i+1] = t + T[i]
		else:
			if i != 0:
				xp = X[i-1]
				tp = T[i-1]
			else:
				xp = 0.0
				tp = 0.0
			
			if T[i]-tp == 0.0:
				ans[i+1] = tp
				continue
				
			v = (X[i]-xp)/(T[i]-tp)
			t = (D-xp)/v
			ans[i+1] = tp + t
	
	#print ans
	return max(ans)

if __name__=='__main__':
	import sys
	f = file(sys.argv[1])
	caseCnt = int(f.readline())
	for case in range(1, caseCnt+1):
		l = f.readline().split()
		D = float(l[0])
		N = int(l[1])
		A = int(l[2])
		x = [0.0]*N
		t = [0.0]*N
		for i in range(N):
			t[i], x[i] = map(float, f.readline().split())
		a = map(float, f.readline().split())
		print "Case #%d:"%case
		for ai in a:
			print '%0.6f'%solve(x, t, D, ai)
