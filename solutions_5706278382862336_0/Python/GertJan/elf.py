#!/usr/bin/env python

import sys

if __name__ == '__main__':
	if len(sys.argv) != 2:
		print 'Give one input file!'
		exit()
	
	#read all input lines
	f = open(sys.argv[1], 'r')
	input = f.readlines()
	f.close()
	
	#how many test cases
	T = int(input[0])
	input_index = 1
	
	for t in xrange(T):
		# read input
		P,Q = map(int, input[input_index].strip().split('/'))
		input_index += 1
		frac = float(P)/float(Q)
		
		# do the division, primary school style
		x = 2
		oldest = None
		for i in xrange(40):
			if frac >= (1.0/x):
				frac -= 1.0/x
				if oldest is None:
					oldest = i+1
			x = x * 2
		
		if frac==0.0:
			print 'Case #%d: %d' % (t+1, oldest)
		else:
			print 'Case #%d: impossible' % (t+1)
