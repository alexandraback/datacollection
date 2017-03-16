import sys
import math

cas = int(sys.stdin.readline())

for i in range(cas):
	arr = sys.stdin.readline().split();
	r = int(arr[0])
	t = int(arr[1])
	a = 2
	b = 2*r-1
	c = -t;
	d = b*b-4*a*c;

	left = 0;
	right = 999999999;
	while left < right:
		q = (left+right+1)/2
		temp = 2*q*r + (2*q-2)*q+q
		if temp <= t:
			left = q
		else :
			right = q-1
	print "Case #%d: %d" % (i+1,left)



