import math

def eval_alt_sum(n):
	if n%2==0:
		return int(n*(n+1)/2)
	else:
		return int(-n*(n+1)/2)

def eval_scenario(anz,r):
	diff = eval_alt_sum(r+2*anz-1)-eval_alt_sum(r-1)
	if diff<0:
		return -diff
	return diff

def bsearch(t,r):
	l = 1
	h = 110000000000
	m = l
	while (h-l)>1:
		m = int(math.floor((l+h)/2))
		if eval_scenario(m,r)>t:
			h = m
		else:
			l = m
	if eval_scenario(h,r)<=t:
		return h
	if eval_scenario(m,r)<=t:
		return m
	return l

N = int(raw_input())
for n in range(N):
	r,t = raw_input().split(' ')
	r,t = int(r), int(t)
	res = bsearch(t,r)
	s = "Case #"+str(n+1)+": "+str(res)
	print s