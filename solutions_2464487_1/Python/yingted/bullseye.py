import gmpy
pi=1
def hex1(n):
	return n*(2*n-1)if n>0 else 0
def ihex1(n):
	return(1+gmpy.fsqrt(8*n+1))/4
def hex2(n):
	return n*(2*n+1)if n>0 else 0
def ihex2(n):
	return(-1+gmpy.fsqrt(8*n+1))/4
for _t in xrange(1,1+int(raw_input())):
	r,t=map(int,raw_input().split())
	hex=hex2 if r&1 else hex1
	ihex=ihex2 if r&1 else ihex1
	area=t/pi+max(0,hex(r/2))
	_n=gmpy.floor(ihex(area))
	print"Case #%d: %d"%(_t,max(n-r/2 for n in xrange(max(0,_n-2),_n+3)if n>=0 and hex(n)<=area))
