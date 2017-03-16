#!/usr/bin/python

import sys

f = open("in1.txt","rb")
t = int(f.readline())

for i in range(t):
	m = f.readline().split()
	n = int(m.pop(0))
	m = map(float,m)
	s = 0.0
	for j in range(n):
		s += m[j]
	#m.sort()
	#m.reverse()
	nn = n
	ss = s

	p = [0.0 for j in range(n)]
	
	print("Case #{0:0d}:").format(i+1),
	for j in range(n):
		if (m[j] >= (2*s/float(n))):
			nn -= 1
			ss -= m[j]
	for j in range(n):
		if (m[j] >= ((ss+s)/float(nn))):
			print ("0.000000"),
		else:
			print ("%.6f" % ((((ss+s)/nn-m[j])/s)*100)),
	print
