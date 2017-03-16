# -*- coding:utf-8 -*-

f = open("input.txt","r")
lines  = int(f.readline())
i = 1

while i<=lines:
	#Problem Start	

	l = f.readline()
	s = l.split()
	r = int(s[0])
	t = int(s[1])

	#arithmetic sequence
	#binary search
	y = 1
	a = 1
	rr = 2*r-1
	s = 0
	low = 0
	high= 1
	while 1:
		d = (y*(2*y+rr))
		if ( t == d ):
			break
		if ( t > d ):
			low = y
			y = y*2
		if ( t < d ):
			high = y
			y = (high+low)/2
			s = s+1
		if ( s == 1000 ):
			while 1:
				d = (y*(2*y+rr))
				if ( t < d ):
					high = y
					y = (high+low)/2
				else:
					break
			while 1:
				d = (y*(2*y+rr))
				if ( t < d ):
					y=y-1
					break
				y=y+1
			break
			

	print "Case #%d: %d" % (i, y)

	#End
	i=i+1

f.close
