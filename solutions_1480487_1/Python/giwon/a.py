def getMinimumPercentages( ccount, points ):
	pointTotal = sum( points )
	avg = 2 * pointTotal / ccount
	candidates = [ p for p in points if p < avg ]
	restCnt = len(candidates)
	if restCnt == 0:
		return [ 100/ccounts for i in range(ccount) ]
	restTotal = sum(candidates)
	restAvg = (restTotal + pointTotal) / restCnt
	p2frac = {}
	for p in candidates:
		p2frac[p] = (restAvg - p) / pointTotal
	res = []
	for p in points:
		if p in p2frac:
			res.append( p2frac[p] )
		else:
			res.append( 0 )
	res = [ 100*frac for frac in res ]

	return res


import sys

fileNamePrefix = sys.argv[1]
fileNameIn = fileNamePrefix + ".in"
fileNameOut = fileNamePrefix + ".out"

fileIn = open( fileNameIn, 'r' )
lines = fileIn.readlines()

testcnt = int( lines[0] )
lineIdx = 1

fileOut = open( fileNameOut, 'w' )

for test in range( testcnt ):
	line = lines[lineIdx].split( ' ' )
	lineIdx += 1

	ccount = int( line[0] )
	points = [ int( p ) for p in line[1:] ]

	res = getMinimumPercentages( ccount, points )
	res = [ "{0:06f}".format(frac) for frac in res ]
	res = " ".join( res )

	fileOut.write("Case #{0}: {1}\n".format(test + 1, res))
