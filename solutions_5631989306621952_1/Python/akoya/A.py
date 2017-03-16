#usr/bin/python
from __future__ import division
import sys

fin = open(sys.argv[1], "r")
fout = open("A.out", "w")
     

T = int(fin.readline())
for ii in xrange(T):
	#n = int(fin.readline())
	s = fin.readline().rstrip()
	sol = s[0]
	for i in range(1,len(s)):
		if s[i] >= sol[0]:
			sol = s[i] + sol
		else:
			sol = sol + s[i]	
	


	

	#sol = s[0] + s[1]	

	fout.write("Case #" + str(ii+1) + ": " + str(sol) + "\n")