
import sys
import math

def possible(X,R,C):
	
	minside = min(R,C)
	maxside = max(R,C)
	area = R*C

	# seven+ can create a hole
	if X >= 7:
		return False

	# must be longer than the straight line om
	if X > maxside:
		return False

	# the smallest side must be longer than the l shape om legs
	if math.ceil(X/2.0) > minside:
		return False

	# we must add up to a integer number of oms
	if area%X != 0:
		return False

	# special case for having a side that can be blocked
	if math.ceil(X/2.0) == minside:
		if X == 6:
			return False
		if X == 5:
			if maxside<=5 or maxside % X != 0:
				return False
		if X == 4:
			return False

	return True

def Calk(X,R,C):

	if possible(X,R,C):
		return "GABRIEL"
	else:
		return "RICHARD"


if __name__ == '__main__':
	
	f = open(sys.argv[1])

	t = int(f.readline())

	for i in range(t):

		[X,R,C] = [ int(x) for x in f.readline().split(" ") ]

		print( "Case #%d: %s" % ( (i+1), Calk(X,R,C) ) )
