from decimal import *
import math

getcontext().prec = 200

infile = open("input.txt", "r")
outfile = open("output.txt", "w")

ncases = int(infile.readline())
for case in xrange(ncases):
	line = infile.readline()
	v = [int(i) for i in line.split()]
	r = Decimal(v[0])
	t = Decimal(v[1])
	a1 = 2*(r+1)-1
	temp = (a1-2)*(a1-2)+8*t
	ttt = -(a1-2) + temp.sqrt()
	ttt = ttt//4
	print >>outfile, "Case #%d: %s" % ((case+1), str(int(ttt)),)
