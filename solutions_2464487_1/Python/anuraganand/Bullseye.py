import sys
import math
import decimal
decimal.getcontext().prec = 100

test=int(raw_input())
tt=1;
while tt <= test:
	list = map(int,raw_input().split())
	r = list[0]
	t = list[1]
	s = int((2*r-1)*(2*r-1)+8*t)
	p=decimal.Decimal(s)**decimal.Decimal(.5)
	d = int(p)
	n = int((d-2*r+1)/4)
	print "Case #%d: %d"%(tt,n)
	tt+=1