#!/usr/bin/pypy
for T in xrange(1,1+int(raw_input())):
	c,f,x=map(float,raw_input().split())
	r=2.
	t=0.
	while True:
		default=t+x/r
		alternate=t+c/r+x/(r+f)
		if alternate>default:
			break
		t+=c/r
		r+=f
	print"Case #%d:"%T,default
