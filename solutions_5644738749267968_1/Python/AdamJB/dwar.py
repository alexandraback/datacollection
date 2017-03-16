#!/usr/bin/env python

def warWins(nLogs, kLogs):
	numRounds = len(nLogs)	
	if numRounds == 1:		
		if nLogs[0] > kLogs[0]:
			return 1
		else:
			return 0			

	numWins = 0

	for curRound in range(0, numRounds):
		numLogsLeft = numRounds - curRound
		# N gives lightest one, k gives least heaviest
		# if k can't give heavier, reamining n wins
		kLastHeavyLogIndex = -1
		nHeavyLog = nLogs.pop(numLogsLeft-1)
		for log in range(0, numLogs - curRound):
			kLog = kLogs[log]
			if kLog > nHeavyLog:
				kLastHeavyLogIndex = log
				break
		if kLastHeavyLogIndex == -1:
			kLogs.pop(0)
			numWins += 1
		else:
			kLogs.pop(kLastHeavyLogIndex)
	return numWins
	

def dWarWins(nLogs, kLogs):
	#print nLogs
	#print kLogs
	numRounds = len(nLogs)	
	if numRounds == 1:		
		if nLogs[0] > kLogs[0]:
			return 1
		else:
			return 0

	numWins = 0
	for curRound in range(0, numRounds):
		numLogsLeft = numRounds - curRound
		# if N can beat K lowest with n lowest, it's a win
		# k will give up its lowest as n bluffs to beat his highest
		nLightLog = nLogs.pop(0)
		kLightLog = kLogs[0]
		if (nLightLog < kLightLog):
			kHeavyLog = kLogs.pop(numLogsLeft-1)
		else:
			kLogs.pop(0)
			numWins += 1

	return numWins

def war(nLogs, kLogs, case):
	numDWarWins = dWarWins(nLogs[:], kLogs[:])
	numWarWins = warWins(nLogs[:], kLogs[:])

	print("Case #%d: %d %d" % (case, numDWarWins, numWarWins))

numCases = int(input())

for case in range(0, numCases):
	numLogs = int(input())
	nLogs = [float(i) for i in raw_input().strip().split()]
	kLogs = [float(i) for i in raw_input().strip().split()]
	war(sorted(nLogs), sorted(kLogs), case+1)
