#!/usr/bin/env python
from sys import stdin

T = int(stdin.readline())
	
for i in xrange(T):
	
	input = map(int, stdin.readline().split(" "))
	N =  input[0]
	
	J = input[1:]
	newcount = list(J)
	
	sumvar = sum(J)
	initsum = sumvar

	while sumvar > 0:
		
		# find the 2nd min
		nbmin = 0
		minvar = min(newcount)
		min2 = max(newcount)
		
		if minvar == min2:  # all flat, finish
			# if sumvar % N == 0:
			# 				toadd= sumvar/N
			# 			else: 
			# 				toadd = (sumvar / N)+1
			toadd = float(sumvar)/N

			for o in xrange(N):
				if newcount[o] == minvar: 
					newcount[o] += toadd
					sumvar -= toadd
					
			break
		
		for o in xrange(N):
			el = newcount[o]
			if el > minvar and el < min2: min2 = el
			if el == minvar : nbmin += 1
		
		if (min2-minvar)*nbmin > sumvar: # not enough pts to distribute
			
		
			# if sumvar % nbmin == 0:
			# 			toadd= sumvar/nbmin
			# 		else: 
			# 			toadd = (sumvar / nbmin)+1
			toadd=float(sumvar)/nbmin
				
			for o in xrange(N):
				if newcount[o] == minvar: 
					newcount[o] += toadd
					sumvar -= toadd

		else :
			for o in xrange(N):
				if newcount[o] == minvar: 
					newcount[o] = min2
					sumvar -= (min2-minvar)
	
	
	print "Case #%d:" % (i+1),
	sc =0
	for o in xrange(N):
#		sc +=  100*float(newcount[o]-J[o])/initsum
		print 100*float(newcount[o]-J[o])/initsum,
		
	print ""
#	print "SCORE: ",sc
	
	