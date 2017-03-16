#!/usr/bin/python -u

# Solves Google Codejam "Deceitful War"
# http://code.google.com/codejam
# Sam Moore (matches)
# 2014-04-11

import sys
import os



def War(n, k, deceitful = False):
	n.sort()
	k.sort()
	#print "Naomi: <I have %s blocks>" % str(n)
	#print "Ken: <I have %s blocks>" % str(k)
	
	points = 0 # Naomi's points (don't care about Ken)
	
	while len(n) > 0:
		N = len(n)
		
		# If Naomi is playing optimally, it does not matter WHAT she does
		# Ken's strategy means he will always choose the same block in response to her choice
		
		# Deceitful strategy: Convince Ken to get rid of his most valuable blocks
		
		if not deceitful:
			ni = N/2
			nt = n[ni]
		else:
			# If we have a block that will beat Ken's worst block, use that
			for lowest_winner in xrange(N):
				if n[lowest_winner] > k[0]:
					break
			if n[lowest_winner] < k[0]:
				lowest_winner = -1
			
			if lowest_winner >= 0: #HURDURP 0 == False != None in python
				nt = k[-1] + 1e-7 # But tell Ken it is good or he will beat it
				ni = lowest_winner
			else:
				ni = 0 # We can't beat any of Ken's blocks, get rid of our worst block
				nt = k[-1] - 1e-7 # But force Ken to use his best block
			
				if n[ni] > nt: # This shouldn't happen
					nt = n[ni]
					sys.stderr.write("No winning block but lowest_winner is None???\n")
					sys.stderr.write(str(n)+"\n"+str(k)+"\n")
					return None
					
				
			
		nc = n[ni]
		#print "Naomi: \"I chose %.7f kg\"" % nt
		#print "Naomi: <I actually chose %.7f kg (%d) >" % (nc, ni)
		
		if nt in k:
			print "Ken: LIAR! That's one of my blocks!"
			return None
	
		# Ken chooses the lightest block that is heavier than Naomi's
		for ki in xrange(N):
			if k[ki] > nt:
				break
		# ... Unless he doesn't have one, in which case he ditches his lightest block
		if k[ki] < nt:
			#print "Ken: <I know I will lose>"
			ki = 0
		kc = k[ki]
		#print "Ken: <I will choose %.7f kg (%d) >" % (kc, ki)
		
		# Play War!
		if kc < nc:
			#print "Naomi: I WON :D"
			points += 1
		#else:
			#print "Naomi: I LOST :-("
			
		# Does Ken get suspicious?
		if nt > kc and nc < kc:
			print "Ken: LIAR! Your block is too light!"
			return None
		if nt < kc and nc > kc:
			print "Ken: LIAR! Your block is too heavy!"
			return None
			
		del n[ni]
		del k[ki]
	return points

def main(argv):
	nCases = int(sys.stdin.readline().strip(" \r\n"))
	
	for c in xrange(1, nCases+1):
		# Solve case
		N = int(sys.stdin.readline().strip(" \r\n"))
		n = map(float, sys.stdin.readline().strip(" \r\n").split(" "))
		k = map(float, sys.stdin.readline().strip(" \r\n").split(" "))
		n.sort()
		k.sort()
		assert len(n) == len(k) == N

		deceitful = War([nn for nn in n], [kk for kk in k], True)
		honest = War([nn for nn in n], [kk for kk in k], False)
		
		
		try:
			print "Case #%d: %d %d" % (c, deceitful, honest)
		except TypeError,e:
			sys.stderr.write("Case #%d: Oh dear.\n"% c)
			sys.stderr.write(str(n) + "\n")
			sys.stderr.write(str(k) + "\n")

			return 1	
	
	return 0

if __name__ == "__main__":
	sys.exit(main(sys.argv))
		
