#!/usr/bin/env python


T = int( raw_input() )
for case in range( 0, T ):
	values = raw_input().split()
	A = int( values[ 0 ] )
	B = int( values[ 1 ] )
	K = int( values[ 2 ] )
	if A <= B:
		smallSeed = A
		bigSeed = B
	else:
		smallSeed = B
		bigSeed = A
	count = 0
	if K >= smallSeed:
		count = smallSeed * bigSeed
	else:
		count = K * bigSeed
		for i in range( K, smallSeed ):
			count += K
			for j in range( K, bigSeed ):
				if i & j < K:
					count += 1
	print "Case #%d: %d" % ( case + 1, count )
