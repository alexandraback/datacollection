#usr/bin/python
from __future__ import division
import sys

fin = open(sys.argv[1], "r")
fout = open("B.out", "w")
     

T = int(fin.readline())
for ii in xrange(T):
	#length = int(fin.readline())
	a = fin.readline().rstrip()
	#print a
	prev = a[0]
	k = 1
	for i in range(len(a)-1):
		if a[i+1] != prev:
			prev = a[i+1]
			k +=1
	print k, k%2 		
	sol = k-1		
	if (k%2 == 1) and (a[0] == '-'):
		sol = k
	if (k%2 ==0) and (a[0] == '+'):
		sol = k
	

	

	fout.write("Case #" + str(ii+1) + ": " + str(sol) + "\n")