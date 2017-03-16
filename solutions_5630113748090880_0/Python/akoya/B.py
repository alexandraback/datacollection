#usr/bin/python
from __future__ import division
import sys

fin = open(sys.argv[1], "r")
fout = open("B.out", "w")
     

T = int(fin.readline())
for ii in xrange(T):
	n = int(fin.readline())
	heights = []
	for i in range(2500):
		heights.append(0)
	for i in range(2*n-1):
		new_line = map(lambda x: int(x), fin.readline().split(' '))
		for k in range(len(new_line)):
			heights[new_line[k]-1] = heights[new_line[k]-1] + 1
	#print heights
	sol = []	
	for i in range(len(heights)):
		if heights[i] % 2 == 1:
			sol.append(i+1)	

	fout.write("Case #" + str(ii+1) + ": " + ' '.join(map(str,sol)) + "\n")