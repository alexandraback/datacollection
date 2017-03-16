INPUT_FILE = "D-large.in"
OUTPUT_FILE = "D-large.out"

import math

global result


	
	
	
def SolveD(KEYS, CHEST_KEYS, CHEST_TYPE, caseNumber):

	global result
	
	
	print caseNumber
	"""print len(CHEST_TYPE)
	print len(KEYS)
	print KEYS
	print CHEST_KEYS
	print CHEST_TYPE
	print"""
	
	N = len(CHEST_TYPE)
	
	chestOrder = [-1 for i in xrange(N)]
	chestNextPosition = 0
	openChests = [False for i in xrange(N)]
	
	while True:
	
		chestOrder[chestNextPosition] += 1
		if (chestOrder[chestNextPosition] == N):
			chestOrder[chestNextPosition] = -1
			chestNextPosition -= 1
			if chestNextPosition == -1:
				#print 'impossible'
				result += "Case #%d: %s\n" %(caseNumber, 'IMPOSSIBLE')
				break
			if openChests[chestOrder[chestNextPosition]] != True:
				print 'Weird'
			openChests[chestOrder[chestNextPosition]] = False
			KEYS.append(CHEST_TYPE[chestOrder[chestNextPosition]])
			for newKey in CHEST_KEYS[chestOrder[chestNextPosition]]:
				KEYS.remove(newKey)
				if chestNextPosition == 10:
					print chestOrder
			continue
			
		if openChests[chestOrder[chestNextPosition]]:
			continue
		if CHEST_TYPE[chestOrder[chestNextPosition]] not in KEYS:
			continue
			
		openChests[chestOrder[chestNextPosition]] = True
		KEYS.remove(CHEST_TYPE[chestOrder[chestNextPosition]])
		for newKey in CHEST_KEYS[chestOrder[chestNextPosition]]:
			KEYS.append(newKey)
			
		if chestNextPosition == N-1:
			#print 'success'
			#print chestOrder
			chestOrderString = ' '.join([str(i + 1) for i in chestOrder])
			result += "Case #%d: %s\n" %(caseNumber, chestOrderString)
			break
		chestNextPosition += 1
		
		
		
		
	#result += "Case #%d: %d\n" %(caseNumber, count)
	return
	
	
	
def SolveDD(KEYS, CHEST_KEYS, CHEST_TYPE, caseNumber):

	global result
	
	
	print caseNumber
	"""print len(CHEST_TYPE)
	print len(KEYS)
	print KEYS
	print CHEST_KEYS
	print CHEST_TYPE
	print"""
	
	N = len(CHEST_TYPE)
	
	
	potentialKeys = []
	for key in KEYS:
		potentialKeys.append(key)
	for i in xrange(N):
		for key in CHEST_KEYS[i]:
			potentialKeys.append(key)
	for i in xrange(N):
		if CHEST_TYPE[i] not in potentialKeys:
			print 'impossible'
			result += "Case #%d: %s\n" %(caseNumber, 'IMPOSSIBLE')
			return
		potentialKeys.remove(CHEST_TYPE[i])
			
	#result += "Case #%d: %s\n" %(caseNumber, 'POSSIBLE MAYBE')

	
	if caseNumber == 200:
		print
		print len(CHEST_TYPE)
		print len(KEYS)
		print KEYS
		print CHEST_KEYS
		print CHEST_TYPE
		print
	
	openChests = [False for i in xrange(N)]
	chestNextPosition = -1
	chestOpenOrder = []

	while True:
		chestNextPosition += 1
		if caseNumber == 200:
			print
			print chestNextPosition
			print openChests
			print chestOpenOrder
			print KEYS
			print
		if chestNextPosition == N:
			if caseNumber == 200:
				print 3333
			break
			
		if openChests[chestNextPosition]:
			if caseNumber == 200:
				print 1111
			continue
		if CHEST_TYPE[chestNextPosition] not in KEYS:
			if caseNumber == 200:
				print 2222
			continue
			
		openChests[chestNextPosition] = True
		KEYS.remove(CHEST_TYPE[chestNextPosition])
		for newKey in CHEST_KEYS[chestNextPosition]:
			KEYS.append(newKey)
	
		if caseNumber == 200:
			print KEYS
	
		queue = []
		COLORED = [False for i in xrange(N)]
		for i in xrange(N):
			if openChests[i] == True:
				continue
			if CHEST_TYPE[i] in KEYS:
				#COLORED[i] = True
				queue.append(i)
				
				
		if caseNumber == 20:
			print COLORED
			
			
			
			
		
		GRAPH = []
		for i in xrange(N):
			GRAPH.append([False for j in xrange(N)])
		
		for i in xrange(N):
			if openChests[i] == True:
				continue			
			for j in xrange(N):
				if openChests[j] == True:
					continue
				if CHEST_TYPE[j] in CHEST_KEYS[i]:
					GRAPH[i][j] = True
					GRAPH[j][i] = True
		
		#queue = []
		#for i in xrange(N):
		#	if openChests[i] == True:
		#		continue	
		#	if (COLORED[i] == True):
		#		queue.append(i)
		
		for i in queue:
			COLORED[i] = True
		while len(queue) > 0:
			nextItem = queue[0]
			queue.remove(nextItem)
			COLORED[nextItem] = True
			for i in xrange(N):
				if openChests[i] == True:
					continue
				if COLORED[i]:
					continue
				if GRAPH[nextItem][i] == True:
					queue.append(i)
		
				
			
		"""
		for iterate in xrange(N):
			for i in xrange(N):
				if openChests[i] == True:
					continue
				if COLORED[i]:
					for j in xrange(N):
						if openChests[j] == True:
							continue
						if CHEST_TYPE[j] in CHEST_KEYS[i]:
							COLORED[j] = True
		"""
		if caseNumber == 20:
			print COLORED
			
		allColord = True
		for i in xrange(N):
			if ((openChests[i] == False) and (COLORED[i] == False)):
				allColord = False
				break
				
		if allColord:
			chestOpenOrder.append(chestNextPosition)
			chestNextPosition = -1
		else:
			openChests[chestNextPosition] = False
			KEYS.append(CHEST_TYPE[chestNextPosition])
			for newKey in CHEST_KEYS[chestNextPosition]:
				KEYS.remove(newKey)
			
	
	if False in openChests:
		print 'impossible'
		result += "Case #%d: %s\n" %(caseNumber, 'IMPOSSIBLE')
		return
	else:
		print 'possible'
		chestOrderString = ' '.join([str(i + 1) for i in chestOpenOrder])
		result += "Case #%d: %s\n" %(caseNumber, chestOrderString)
		return
			












file = open(INPUT_FILE, 'rb').read()

fileLines = file.replace('\r\n','\n').split('\n')

T = int(fileLines[0])
nextLine = 1

result = ""

for t in xrange(T):

	(K,N) = fileLines[nextLine].split(' ')
	(K,N) = (int(K), int(N))
	nextLine += 1
	KEYS = fileLines[nextLine].split(' ')
	KEYS = [int(i) for i in KEYS]
	nextLine += 1
	CHEST_KEYS = []
	CHEST_TYPE = []
	for i in xrange(N):
		currentChest = fileLines[nextLine].split(' ')
		nextLine += 1
		CHEST_TYPE.append(int(currentChest[0]))
		CHEST_KEYS.append([int(j) for j in currentChest[2:]])
	
	#if t == 0 or t == 1 or t == 2 or t == 6 or t == 7 or t == 8 or t == 9 or t == 11 or t == 12 or t == 14 or t == 15 or t == 16 or t == 18 or t == 19 or t == 20 or t == 21 or t == 22 or t == 23:
	#SolveD(KEYS, CHEST_KEYS, CHEST_TYPE, t+1)
	SolveDD(KEYS, CHEST_KEYS, CHEST_TYPE, t+1)
	
	
open(OUTPUT_FILE, "wb").write(result)

