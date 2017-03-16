import sys
import linecache
import math

linecache.getline(sys.argv[1], 1)

line_counter = 2

for k in range(0, int(linecache.getline(sys.argv[1], 1))):

	line = linecache.getline(sys.argv[1], line_counter)
	(r, t) = [float(x) for x in line.split()]

	crap = ((1-2*r)+math.sqrt((2*r-1)**2+8*t))/4
	crap = int(crap)


	for i in range(max(crap-10,0),crap+10):
		if (2*r*i+2*i**2-i) > t:
			break

	print "Case #%d: %d" % (k+1, i-1)

	line_counter += 1
