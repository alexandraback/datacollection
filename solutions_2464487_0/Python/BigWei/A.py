from __future__ import division
from math import *
import sys
a = raw_input();
def check(r , t , cur):
	temp = r *2*cur +(1+4*(cur-1) +1)/2 * cur;
	if temp <= t :
		return True;
	return False;
for n in xrange(int(a)):
	b=  raw_input();
	r , t = b.split();
	r = int(r)
	t = int(t);
	s = 1;
	d = t/2;
	ans = 0;
	while s <= d:
		mid = floor((s+d)/2);
		if check(r , t,mid) == True:
			ans = mid;
			s = mid+1;
		else:
			d= mid-1;
	print 'Case #%d:' % (n+1),int(ans)
