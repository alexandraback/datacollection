#!/bin/sh

fname = 'A-small-attempt0'
#fname = 'A-example'

from itertools import *

def tokreader(filename):
	for line in open(filename):
		for item in line.strip().split():
			yield item

def readn(n):
    r = []
    for i in xrange(n):
        r.append(read)
    return r

def solve():
	inp = tokreader(fname+'.in')
	read = lambda: inp.next()
	readn = lambda x:[read() for i in xrange(x)]
	outp = open(fname+'.out','w')

	
	d = [1000002] * 1000002
	
	
	d[1] = 1
	
	x = 1
	
	aset = set()
	aset.add(1)
	
	while (len(aset)>0):
		x = aset.pop()
		if x+1 <= 1000000:
			if (d[x+1] > d[x] + 1):
				d[x+1] = d[x] + 1
				aset.add(x+1)
		
		xr = str(x)[::-1]
		while xr[0] == '0':
			xr = xr[1:]
		xr = int(xr)
		if xr <= 1000000:
			if (d[xr] > d[x] + 1):
				d[xr] = d[x] + 1
				aset.add(xr)
		

	T = int(read())
	for i in range(1,T+1):
		N = int(read())
		
		
			
		res = 'Case #%d: %d\n'%(i,d[N])
		print res
		outp.write(res)
		

	outp.close()
	print 'finished'
