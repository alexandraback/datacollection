#! /usr/bin/env python
from itertools import count

fname = 'B-small-attempt0'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')

def solve(fin):
	C, F, X = map(float, fin.readline().split())
	f = 0
	rate = 2.0
	twin = X/rate
	for i in count(1):
		ft = C/rate
		rate += F
		tnewwin = X/rate
		f += ft
		if twin > f + tnewwin:
			twin = f + tnewwin
		else:
			return twin # i is too many factories, so previous value

T = int(fin.readline())

for i in xrange(1,T+1):
	fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
