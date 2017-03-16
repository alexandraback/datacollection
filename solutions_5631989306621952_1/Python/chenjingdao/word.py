#!/usr/bin/python
import sys
f = open('a.in')
l = int(f.readline())
for i in range(l):
	s = f.readline().strip()
	ss = s[0]
	for c in s[1:]:
		if c >= ss[0]:
			ss = c + ss
		else:
			ss += c
	print 'Case #'+str(i+1)+": "+ss
