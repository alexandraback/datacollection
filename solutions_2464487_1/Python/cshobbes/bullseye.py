from mpmath import *

mp.dps = 100
mp.pretty = True

filename = 'A-large.in'
file = open(filename, 'r')
lines = file.read().splitlines()
numTests = int(lines[0])

index = 0
for testNum in range(numTests):
	index += 1
	inputParams = lines[index].split(' ')
	initRadius = int(inputParams[0])
	totalPaint = int(inputParams[1])
	numRings = 0
	b = (initRadius * 2) - 1
	# print "sqrt = %s" %(sqrt(b*b + (8*totalPaint)))
	# print "b = %s" %b
	# print "sqrt-b = %s" %(-b+sqrt(b*b + (8*totalPaint)))
	n = int((-b + sqrt(b*b + (8*totalPaint))) / 4)
	
	# print "totalPaint %s" %totalPaint
	# while True:
	# 	newNumRings = numRings + 1
	# 	paintToUse = 2*initRadius*newNumRings + 2*newNumRings*newNumRings - newNumRings
	# 	print "ToUse %s" %paintToUse

	# 	if paintToUse > totalPaint:
	# 		break
	# 	else:
	# 		numRings += 1
		# paintToUse = ((currentRadius+1)**2) - (currentRadius**2)
		# print "CurrentR: %s, paintLeft: %s, ringNum: %s" %(currentRadius, currentPaint, numRings)
		
		# if currentPaint < paintToUse:
		# 	break
		# else:
		# 	# currentRadius += 2
		# 	currentPaint -= paintToUse
		# 	paintToUse += 4
		# 	numRings += 1
	print "Case #%d: %s" %(testNum+1, n)
	# a = raw_input("WAIT")

