#!/usr/bin/python

import math
import sys



def isGood(num, t):
	#print("num = %d , t = %d") % (num, t)
	return (2*num*num + (2*r - 1)*num) <= t






T = raw_input()
idx = 0
while((idx) <= T):
	#t = long(raw_input())
	#r = long(raw_input())
	tmp = raw_input().split()
	r = long(tmp[0])
	t = long(tmp[1])
	lim = 1L
	
	mid = 0L
	lo = 1L
	high = t

	while(lo < high):
		mid = (lo + high) / 2L
		#print("mid = %d") % mid
		if isGood(mid, t) and (not isGood(mid+1, t)):
			break
		if(isGood(mid, t)):
			lo = mid
		else:
			high = mid

	#while(isGood(lim, t)):
	#	lim *= 2L

	#res = lim / 2L
	#print("lim = %d") % lim
	#while(res <= lim):
	#	if(not isGood(res+1, t)):
	#		break
	#	res = res + 1
	idx = idx + 1


	print "Case #%d: %d" % (idx, mid)







