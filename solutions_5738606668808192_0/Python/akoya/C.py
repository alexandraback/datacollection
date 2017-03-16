#usr/bin/python
from __future__ import division
import sys
import itertools

fin = open(sys.argv[1], "r")
fout = open("C.out", "w")
     

T = int(fin.readline())
for ii in xrange(T):
	n, j = map(lambda x: int(x),(fin.readline().split()))
	fout.write("Case #" + str(ii+1) + ":" + "\n")
	#a = fin.readline().rstrip()
	#print a
	#print n, j
	
	lst = list(itertools.product([0, 1], repeat=(int(n/2) -1)))
	for i in range(j):
		new_lst = [1] + list(lst[i]) + list(lst[i][::-1]) + [1]
		sol =  ''.join(map(lambda x: str(x), new_lst))
		fout.write(sol + " 3 2 5 2 7 2 9 2 11" + "\n")

	#num = 8
	#print num**15+1+num**14+num+num**5+num**10	



	

	

	