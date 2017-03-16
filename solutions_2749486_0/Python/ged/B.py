#!/usr/bin/python
import sys
import random
import math


inp = [l.strip() for l in sys.stdin]
T = int(inp[0])
l = 1
for t in range(T):
	arr = inp[l].split(" ")
	l += 1

	X = int(arr[0])
	Y = int(arr[1])

	while True:
		k = 1
		x = X
		y = Y
		s = ""
		while True:
			dir =''
			if k<abs(X) and k<abs(Y):
				dir = 'x' if random.randint(0,1)==0 else 'y'
			elif k<abs(X):
				dir = 'x'
			elif k<abs(Y):
				dir = 'y'

			if dir=='x':
				if x<0:
					s += 'W'
					x += k
				else:
					s += 'E'
					x -= k
			elif dir=='y':
				if y<0:
					s += 'S'
					y += k
				else:
					s += 'N'
					y -= k
			else:
				break
			k += 1#

#		s+= "."
#		print "---",x,y
		while x>0:
			s += 'WE'
			k += 2
			x -= 1
		while x<0:
			s += 'EW'
			k += 2
			x += 1
		while y>0:
			s += 'SN'
			k += 2
			y -= 1
		while y<0:
			s += 'NS'
			k += 2
			y += 1

		k=1
		x=0
		y=0
		for c in s:
			if c=='N':
				y+=k
			if c=='S':
				y-=k
			if c=='E':
				x+=k
			if c=='W':
				x-=k
			k+=1
		if x!=X or y!=Y:
			raise "VALIDATION ERROR"
		if len(s)<=500:
			break

	#print "End with k=",k,"at ",x,",",y
	print "Case #%d: %s" % (t+1, s)

