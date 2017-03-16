#!/usr/bin/env python

from sys import stdin
import string

tab = string.maketrans('abcdefghijklmnopqrstuvwxyz', 'yhesocvxduiglbkrztnwjpfmaq')

TC = int(stdin.readline().strip())
for tc in xrange(1,TC+1):
   print 'Case #%d: %s' % (tc, stdin.readline().translate(tab)),
