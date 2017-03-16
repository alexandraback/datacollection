T = int(raw_input())
for kei in xrange(T):
	E,R,N = (int(x) for x in raw_input().split())
	v = [int(x) for x in raw_input().split()]
	dp = {}
	def f(n,e):
		if n == N:
			return 0
		else:
			if (n,e) not in dp:
				vv = f(n+1,min(e+R,E))
				if e != 0:
					vv = max(vv,f(n,e-1)+v[n])
				dp[(n,e)] = vv
			return dp[(n,e)]
	print('Case #%d: %d' % (kei+1, f(0,E)))