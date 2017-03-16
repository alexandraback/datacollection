#!/bin/env python2
import decimal, sys

T = int(sys.stdin.readline())
one = decimal.Decimal(1)
two = decimal.Decimal(2)
four = decimal.Decimal(4)
eight = decimal.Decimal(8)
for cas in range(T):
	line = sys.stdin.readline().split()
	r = decimal.Decimal(line[0])
	t = decimal.Decimal(line[1])
	ans = ((one-r*two)+((r*two-one)*(r*two-one)+eight*t).sqrt())/four
	ans = ans.to_integral_exact()
	while ans*ans*two+(two*r-one)*ans > t:
		ans = ans-one
	print 'Case #'+str(cas+1)+': ' + str(ans)

