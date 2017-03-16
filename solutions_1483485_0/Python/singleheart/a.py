#!/usr/bin/python

# B. cow

import sys

from string import maketrans

intable = "yhesocvxduiglbkrztnwjpfmaq"
outtable = "abcdefghijklmnopqrstuvwxyz"
table = maketrans(outtable, intable)

f = sys.stdin
T = int(f.readline())

for t in range(1, T+1):
	print "Case #%d: %s" % (t, f.readline().strip().translate(table))
