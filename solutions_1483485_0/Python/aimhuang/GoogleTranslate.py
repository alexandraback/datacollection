#!/usr/bin/env python
from sys import stdin
T=int(stdin.readline())

a=dict()
a['y']='a'
a['e']='o'
a['q']='z'
a['z']='q'

b="ejp mysljylc kd kxveddknmc re jsicpdrysi"
bb="our language is impossible to understand"
l=len(bb)
for i in range(0,l):
	a[ b[i] ]=bb[i]
b="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
bb="there are twenty six factorial possibilities"
l=len(bb)
for i in range(0,l):
	a[ b[i] ]=bb[i]
b="de kr kd eoya kw aej tysr re ujdr lkgc jv"
bb="so it is okay if you want to just give up"
l=len(bb)
for i in range(0,l):
	a[ b[i] ]=bb[i]

for case in range(1, T+1):
	s=stdin.readline().strip()
	y=""
	for e in s:
		y+=a[e]
	
	print "Case #%d:"%case, y
