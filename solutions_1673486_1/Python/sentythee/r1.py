#!/usr/bin/python

from sys import *

readline = stdin.readline
mult = lambda x,y: x*y

cases = int(readline().strip())

for i in range(0, cases):
	case = i+1
	typed, total = [int(x) for x in readline().strip().split()]
	probs = [float(x) for x in readline().strip().split()]
	
	keyprob = {}
	runningprob = 1.0
	
	for i in range(0, typed+1):
		keyprob[i] = ((total - i + 1 + typed - i) * runningprob) + ((total - i + 1 + typed - i + total + 1) * (1 - runningprob))
		
		if i != typed:
			runningprob = runningprob * probs[i]
	
	
	lowest = min(keyprob.values())
	lowest = min(lowest, total+2)
	
	print 'Case #%d: %s' % (case, lowest)
