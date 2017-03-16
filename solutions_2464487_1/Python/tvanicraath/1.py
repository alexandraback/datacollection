from math import *
from decimal import *
n = int(raw_input())
for i in range(1,n+1):
	in1 = raw_input()
	in2 = in1.split(' ');
	r=int(in2[0]);
	t=int(in2[1]);
	a=2;
	b=r+r-1;
	c=-t;
	d=(b*b)-(4*a*c)
	getcontext().prec = 100
#	d=sqrt(d)
#	d=d**.5
	numbits=int(log(d,2) + 1)
	numbits=numbits/2;
	x = 2**ceil(int(numbits))
	for j in range(0,100):
	    y = floor((x + floor(d/x))/2)
	    if y>=x:
	        break
	    x = y
	d=Decimal(d).sqrt()
	d=-b+d
	d=d/(2*a)
	d=(int (d))
	print "Case #"+str(i)+": "+str(d)
