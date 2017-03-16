#usr/bin/python
from __future__ import division
import sys

fin = open(sys.argv[1], "r")
fout = open("D.out", "w")
     

T = int(fin.readline())
for ii in xrange(T):
	k, c, s = map (lambda x: int (x),fin.readline().split())
	print k, c, s
	p = c-1
	num = 0
	sol = []
	for i in range(k):
		num += i * k**p
		print num
		if p == 0:
			sol.append(num+1)
			num = 0
			p = c
		p -= 1
	if num != 0:
		sol.append(num+1)
	if k == 1 :
		sol = [1]		


	print sol
	if len(sol) > s:
		sol = "IMPOSSIBLE"	
	else:	
		sol = ' '.join(map(lambda x: str(x), sol))	
	fout.write("Case #" + str(ii+1) + ": " + str(sol) + "\n")