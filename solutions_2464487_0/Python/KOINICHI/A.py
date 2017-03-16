import math

def sum(n) :
	return (1+n)*n/2
	
T = input();
for k in range(T):
	r,t = map(int,raw_input().split())
	
	l,h=(1,1000000000)
	ret = None
	while l<=h:
		m = (l+h)/2
		
		area = (2*r)*m + sum(m*2-1);
		if area <= t:
			ret = m
			l = m+1
		else:
			h = m-1
	print "Case #" + str(k+1) + ": " + str(ret)
	