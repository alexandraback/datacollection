def getDigs(num):
	if num == 0:
		result = []
		return result
	result = getDigs(num/10)
	result.append(num%10)
	return result

f = open('A-large.in')
curr_line = f.readline()
numCases = int(curr_line)
output = ""
for i in range(0,numCases):
	
	curr_line = f.readline()
	N = int(curr_line)
	if N == 0:
		print "Case #%d: INSOMNIA" %(i+1)
	else:
		digsSeen = []
		for n in range(0,10):
			digsSeen.append(False)
		allSeen = True
		curr = N
		digs = getDigs(curr)
		for d in digs:
			digsSeen[d] = True
		for d in digsSeen:
			if not d:
				allSeen = False
		curr = N
		x = 0
		while not allSeen and x < 100:
			curr = curr + N
			digs = getDigs(curr)
			for d in digs:
				digsSeen[d] = True
			allSeen = True
			for d in digsSeen:
				if not d:
					allSeen = False
			x += 1
		print "Case #%d: %d" %(i+1,curr)



