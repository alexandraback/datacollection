import math
def p(h,t):
	d,m=h
	return abs(int(math.floor((t-m*(360-d))/(360.*m))))
for tc in range(input()):
	N=input()
	HG=[map(int,raw_input().split())for n in range(N)]
	H=[(D,M+h)for D,H,M in HG for h in range(H)]
	T=[(360-d)*m+n*m for d,m in H for n in range(-1,100)]
	res=float('inf')
	for t in sorted(T)[:1000]:
		u=0
		for h in H:
			u+=p(h,t)
		res=min(res,u)
	print'Case #{}: {}'.format(tc+1,res)