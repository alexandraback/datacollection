# -*- coding:utf-8 -*-

f = open("input.txt","r")
lines  = int(f.readline())
i = 1

while i<=lines:
	#Problem Start	
	l = f.readline()
	r = l.split()
	E = int(r[0])
	R = int(r[1])
	N = int(r[2])
	l = f.readline()
	D = l.split()

	A = E

	for d in D:
		v = int(d)
		if v==1:
			continue
		else:
			A=A+E*v+R-E

	print "Case #%d: %d" % (i, A)
	#End
	i=i+1
f.close
