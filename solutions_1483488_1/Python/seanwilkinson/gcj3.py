f = open('C-large.in')
g = open('C-large.out', 'wt')

T = int(f.readline().strip())

def bigger(nString, i, depth):
	digits = len(nString)
	testvalue = int(nString[(i+depth)%digits]) - int(nString[depth])
	if depth < digits -1:
		if testvalue > 0:
			return True
		elif testvalue < 0:
			return False
		else:
			return bigger(nString, i, depth+1)
	else:
		if testvalue > 0:
			return True
		else:
			return False


for line in range(0, T):
	testcase = f.readline().strip().split()
	pairs = 0
	A, B = int(testcase[0]), int(testcase[1])
	maxdigits = len(str(B))
	for n in range(A,B):
		nMatches = set([])
		nString = str(n)
		digits = len(nString)
		if digits < maxdigits:
			for i in range(1, digits):
				if bigger(nString, i, 0):
					MatchCandidate = nString[i:] + nString[:i]
					if MatchCandidate not in nMatches:
						pairs += 1
						nMatches.add(MatchCandidate)
					else:
						pass
		else:
			for i in range(1, digits):
				if int(nString[i:] + nString[:i]) <= B:
					if bigger(nString, i, 0):
						MatchCandidate = nString[i:] + nString[:i]
						if MatchCandidate not in nMatches:
							pairs += 1
							nMatches.add(MatchCandidate)
						else:
							pass
	g.write('Case #' + str(line+1) + ': ' + str(pairs) + '\n')
	
f.close()
g.close()
		
