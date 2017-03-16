import sys
import math

file = open(sys.argv[1])
first = True
T = 1
def fun(n,r):
	return n*(2*(2*r+1)+(n-1)*4)/2
	
for line in file:
	if first:
		first = False
		continue
	tmp = line.split()
	r = int(tmp[0])
	t = int(tmp[1])
	ans = int((t+3)/(2*r+4))
	i = 1
	f = t+1
	while(i<f):
		m=(i+f)/2
		x = fun(m,r)
		if (x == t): 
			i = m+1
			break
		if (x > t): f = m
		else: i = m+1
	print "Case #%d: %d" % (T, i-1)
	T+=1
