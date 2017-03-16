import sys
import time
import math



with open(sys.argv[1]) as f:
	T  = int(f.readline())
	content = f.readlines()


def solve(X,Y):
	pos = [(0,0,'')]
	for i in range(500):
		d = i+1
		newpos = []
		buf = {}
		def tryAdd(a,b,c):
			k = str(a)+"x"+str(b)
			if k not in buf:
				newpos.append((a,b,p[2]+c))
			buf[k] = True
		for p in pos:
			x = p[0]
			y = p[1]


			tryAdd(x+d,y,"E")
			tryAdd(x-d,y,"W")
			tryAdd(x,y+d,"N")
			tryAdd(x,y-d,"S")
			#newpos.append((x+d,y,p[2]+'E'))
			#ewpos.append((x,y+d,p[2]+'N'))
			#newpos.append((x,y-d,p[2]+'S'))
			#newpos.append((x-d,y,p[2]+'W'))
		
		for p in newpos:
			if p[0] == X and p[1] == Y:
				return p[2]
		#print len(pos)
		pos = newpos
	return "HUH?"




for t in range(T):
	row = content[t].strip().split()
	X = int(row[0])
	#name = "nnnnnnnnnn"*100000
	Y  = int(row[1])
	f = solve(X,Y)
	print "Case #%d: %s" % (t+1,f)

