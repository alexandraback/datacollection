#!/usr/bin/python

import sys

def completeallwithtwo(levels,currentStars,completedLevels):
	earnedstars=1
	advanced=0	
	while earnedstars>0:
		earnedstars=0;
		for level in levels:
			if (level[1]<=currentStars) and (level[2]==0):
				level[2]=2
				currentStars=currentStars+2
				earnedstars=earnedstars+2
				advanced=1
				completedLevels=completedLevels+1
			if (level[1]<=currentStars) and (level[2]==1):
				level[2]=2
				advanced=1
				currentStars=currentStars+1
				completedLevels=completedLevels+1
				earnedstars=earnedstars+1
	return (currentStars,completedLevels,advanced)

def completeonewithone(levels,currentStars,completedLevels):
	for level in levels:
		if (level[0]<=currentStars) and (level[2]==0):
			level[2]=1
			currentStars=currentStars+1
			completedLevels=completedLevels+1
			return (currentStars,completedLevels,1)
	return (currentStars,completedLevels,0)			

def processCase(nlevels,levels):
	# *** BEGIN CODE PROCESSING CASE ***

	currentStars=0
	completedLevels=0;	
	advanced=1

	while advanced>0:
		currentStars,completedLevels,advanced=completeallwithtwo(levels,currentStars,completedLevels)				
		currentStars,completedLevels,advanced2=completeonewithone(levels,currentStars,completedLevels)
		advanced=advanced+advanced2

	if currentStars!=(nlevels*2):
		return "Too Bad"

	# *** END CODE PROCESSING CASE ***
	return str(completedLevels) 

def readCase(case):

	# *** BEGIN CODE READING CASE ***
	caseInput=sys.stdin.readline()

	levels=[]
	nlevels=int(caseInput)
	for l in xrange(nlevels):
		cad=sys.stdin.readline()
		lvl=[int(cad.split()[0]),int(cad.split()[1]),0]
		levels.append(lvl)

	# *** END CODE READING CASE ***

	solution=processCase(nlevels,levels)
	print "Case #"+str(case)+": "+solution

cases=int(sys.stdin.readline())

for case in range(cases):
	readCase(case+1)

