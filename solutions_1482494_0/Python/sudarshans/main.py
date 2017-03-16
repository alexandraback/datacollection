numcases=int(raw_input())

for i in xrange(0,numcases):
	numLevels=int(raw_input())

	levels=[]
	for xi in xrange(0,numLevels):
		cl=map(int,raw_input().split())
		levels.append(cl)

	levels.sort()
	lvl2solved=[False]*len(levels)

	numGames=0
	rating=0
	currentLvl1=0
	solvlv2=0
	print "Case #%d:"%(i+1),
	#now advance one by one in the game
	#till we have to backtrack
	while True:
		#can he play one more level@1star?
		if solvlv2==len(levels):
			print numGames
			break
		if currentLvl1 >= len(levels):
			if levels[currentLvl1-1][1] <= rating:
				print numGames+1
				break
			else:
				print "Too Bad"
				break
		if levels[currentLvl1][1] <= rating:
			rating+=2 #and gets better rating
			lvl2solved[currentLvl1]=True
			currentLvl1+=1
			numGames+=1
			solvlv2+=1
		elif levels[currentLvl1][0] <= rating:
			rating+=1 #and gets better rating
			currentLvl1+=1
			numGames+=1
		else: #has to backtrack
			done=False
			for backtrack in xrange(currentLvl1,-1,-1):
				#we are at level backtrack now
				if not lvl2solved[backtrack] and levels[backtrack][1] <= rating:
					numGames+=1 #plays another game
					rating+=1 #and gets better rating
					done=True
					lvl2solved[backtrack]=True
					solvlv2+=1
					break
			if not done:
				print "Too Bad"
				break
