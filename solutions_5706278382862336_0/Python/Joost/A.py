#! /usr/bin/env python

from fractions import gcd

fname = 'A-small-attempt1'
fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')

twopow = [2 ** i for i in range(40)]

def redfrac(P, Q):
	g = gcd(P, Q)
	return (P/g, Q/g)

def solve(fin):
	P, Q = map(int, fin.readline().split('/'))
	if Q not in twopow:
		return 'impossible'
	for i in range(0,41):
		if P * twopow[i] < Q and P * twopow[i+1] >= Q: #P/Q < 1 / (2 ** i) and P/Q >= 1 / (2 ** (i+1)) # P/Q is lower than 1/(2 ** i) and higher than 1/(2 ** (i+1))
			return i+1
	return 'impossible'
	
T = int(fin.readline())
for i in xrange(1,T+1):
	fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
