#!/usr/bin/python
import sys

gs="y qee"+\
 "ejp mysljylc kd kxveddknmc re jsicpdrysi"+\
 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+\
 "de kr kd eoya kw aej tysr re ujdr lkgc jv"

es="a zoo"+\
 "our language is impossible to understand"+\
 "there are twenty six factorial possibilities"+\
 "so it is okay if you want to just give up"

e2g = {}
g2e = {}

for (g,e) in zip(gs,es):
	if e==' ' or g==' ':
		if e!=' ' or g!=' ':
			raise Exception("bad space")
		else:
			continue
	if g in g2e and g2e[g]!=e:
		raise Exception("g2e:"+str((g,e)))
	if e in e2g and e2g[e]!=g:
		raise Exception("g2e:"+str((g,e)))
	e2g[e] = g
	g2e[g] = e
#print len(e2g)


ez = None
gz = None
for i in range(26):
	z = chr(ord('a')+i)
	if z not in e2g:
		ez = z
	if z not in g2e:
		gz = z

#print "last pair",(ez,gz)
e2g[ez] = gz
g2e[gz] = ez
g2e[' '] = ' '
e2g[' '] = ' '

inp = [s.strip() for s in sys.stdin][1:]
l = 1
for s in inp:
  s2 = "".join([g2e[x] for x in s])
  print "Case #%d: %s" % (l, s2)
  l += 1

