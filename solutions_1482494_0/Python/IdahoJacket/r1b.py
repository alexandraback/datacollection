import sys

def finished( levels ):
	for level in levels:
		if ( level[2] != 2 ):
			return False

	return True

numCases = input()
for case in range( 1, numCases + 1 ):
	numLevels = input()

	levels = []
	for i in range( 0, numLevels ):
		( one, two ) = raw_input().split()
		one = int(one)
		two = int(two)
		foo = []
		foo.append( one )
		foo.append( two )
		foo.append( 0 )
		levels.append( foo )
	
	numStars = 0
	numGames = 0


	fail = False
	numFinishedLevels = 0

	while( numFinishedLevels < numLevels ):
		oneStar = -1
		oneStarTieBreak = -1
		twoStar = -1
		for i in range( 0, numLevels ):
			level = levels[i]
			if ( level[2] == 0 and level[1] <= numStars ):
				twoStar = i	
				break
			if ( level[2] == 1 and level[1] <= numStars ):
				oneStar = i
				oneStarTieBreak = 9999999999
			if ( level[2] == 0 and level[0] <= numStars ):
				if ( level[1] > oneStarTieBreak ):
					oneStar = i
					oneStarTieBreak = level[1]

			++i

		if ( twoStar != -1 ):
			numStars += 2
			numGames += 1
			levels[twoStar][2] = 2
			numFinishedLevels += 1
		elif ( oneStar != -1 ):
			numStars += 1
			numGames += 1
			levels[oneStar][2] = levels[oneStar][2] + 1
			if ( levels[oneStar][2] == 2 ):
				numFinishedLevels += 1
		else:
			fail = True
			break


	if ( fail ):
		print 'Case #' + str( case ) + ': Too Bad' 
	else:
		if ( numGames < numLevels or numGames > 2 * numLevels ):
			print "ERROR!!!!"
			print i, numGames, numLevels
		print 'Case #' + str( case ) + ': ' + str( numGames ) 
