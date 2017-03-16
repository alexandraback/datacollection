#!/usr/bin/python
T = int(raw_input())

for j in range(T):
	p = raw_input()
	l = len(p)
	f = 0
	for i in range(l):
		index = l-1-i
		c = p[index]

		if c == '+' and f %2 == 1:
			f+=1
		elif c == '-' and f%2 == 0:
			f+=1

	print "Case #%d: %d"%(j+1, f)


