#!/usr/bin/pypy
import itertools
import sys

if __name__ == '__main__':
	trns = [chr(i) for i in xrange(256)]
	trns[ord('a') : ord('z') + 1] = 'yhesocvxduiglbkrztnwjpfmaq'
	trns = ''.join(trns)

	n = int(raw_input())
	for i in xrange(n):
		s = raw_input()
		print "Case #{}: {}".format(i + 1, s.translate(trns))

