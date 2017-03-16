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

	print "Case #%d: %d" % (k+1, crap)

	line_counter += 1
