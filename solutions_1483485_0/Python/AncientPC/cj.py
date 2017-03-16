#!/usr/bin/env python2

import string
g = string.maketrans(
	"ynficwlbkuomxsevzpdrjgthaq",
	"abcdefghijklmnopqrstuvwxyz")

nc = int(raw_input())
for c in xrange(nc):
	s = string.translate(raw_input(),g)

	print "Case #%i: %s" % (c+1, s)
