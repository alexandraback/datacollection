#!/usr/bin/python -u

# Solves Google Codejam "Cookie Clicker Alpha"
# http://code.google.com/codejam
# Sam Moore (matches)
# 2014-04-11

import sys
import os

def main(argv):
	nCases = int(sys.stdin.readline().strip(" \r\n"))
	
	for c in xrange(1, nCases+1):
		# Solve case
		C, F, X = map(float, sys.stdin.readline().strip(" \r\n").split(" "))
		R = 2.0 # Constant initial rate

		# The problem simplifies to "How many farms should we buy before stopping"
		# Create series of how long it will take to get the cookies if we stop at N farms
		# Wait for the minima of the series.

		# It took me way too long to get this.

		tprev = X/R
		t = X/R
		n = 1
		while t <= tprev:
			tprev = t
			t = tprev - X/(R + (n-1)*F) + C / (R + (n-1)*F) + X/(R + n*F)
			n += 1

		print "Case #%d: %.7f" % (c, tprev)
	
	return 0

if __name__ == "__main__":
	sys.exit(main(sys.argv))
		
