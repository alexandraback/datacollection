import sys

def eval(r,n):
	return n*(2*n+2*r-1)

def solve(r,t):
	min=0
	sup=1
	while eval(r,sup)<=t: sup *= 2
	while sup>min+1:
		mid = (min+sup)/2
		if eval(r,mid)<=t:
			min=mid
		else:
			sup=mid
	return min

cases=int(sys.stdin.readline())
for case in range(cases):
	rt = sys.stdin.readline().split(' ')
	assert len(rt)==2
	r=int(rt[0])
	t=int(rt[1])
	n = solve(r,t)
	print 'Case #'+str(case+1)+': '+str(n)

