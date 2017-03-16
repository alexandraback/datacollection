#usr/bin/python
from __future__ import division
import sys

fin = open(sys.argv[1], "r")
fout = open("A.out", "w")
     

T = int(fin.readline())
for ii in xrange(T):
	n = int(fin.readline())
	#a = fin.readline().rstrip()
	#print a
	if n==0:
		sol = 'INSOMNIA'
	else:
		tlist = ['0','1','2','3','4','5','6','7','8','9']
		k = 0
		num = n	
		while tlist:
			k += 1
			for i in range(len(str(num))):
				#print str(n)[i]
				if str(num)[i] in tlist:
					tlist.remove(str(num)[i])
			num = n*(k+1)	
		sol = n*k		


	

	

	fout.write("Case #" + str(ii+1) + ": " + str(sol) + "\n")