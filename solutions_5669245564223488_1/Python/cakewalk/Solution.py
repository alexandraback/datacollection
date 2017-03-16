from sys import stdin
readline = stdin.readline

MOD = 1000000007

Fact = [1]
for i in xrange(1, 101):
	Fact.append((i*Fact[-1]) % MOD)

def full(s, c):
	for i in s:
		if i != c:
			return False
	return True

def end(s, c):
	return s[-1] == c

def begin(s, c):
	return s[0] == c

def middle(s, c):
	return (s[0] != x and s[-1] != c and c in s)

T = int(readline())
for t in xrange(1, T+1):
	N = int(readline())
	
	Strings = readline().split()
	Strings = map(lambda s: [ord(c)-ord('a') for c in s], Strings)
	
	flag = True
	for i in xrange(len(Strings)):
		Count = [0]*26
		Count[Strings[i][0]] = 1
		for j in xrange(1, len(Strings[i])):
			if Count[Strings[i][j]] != 0 and Strings[i][j-1] != Strings[i][j]:
				flag = False
				break
		if not(flag):
			break
	if not(flag):
		print 'Case #%d: 0' % (t)
		continue
	
	Full = [[] for i in xrange(26)]
	Start = [[] for i in xrange(26)]
	End = [[] for i in xrange(26)]
	Middle = [[] for i in xrange(26)]
	
	for i in xrange(len(Strings)):
		if Strings[i][0] == Strings[i][-1]:
			Full[Strings[i][0]].append(i)
		else:
			Start[Strings[i][0]].append(i)
			End[Strings[i][-1]].append(i)
			for j in xrange(1, len(Strings[i])-1):
				if Strings[i][j] not in [Strings[i][0], Strings[i][-1]] and Strings[i][j] != Strings[i][j-1]:
					Middle[Strings[i][j]].append(i)
	
	for i in xrange(26):
		if Middle[i] != []:
			if Start[i] != [] or End[i] != [] or Full[i] != []:
				flag = False
				break
	if not(flag):
		print 'Case #%d: 0' % (t)
		continue
	
	for i in xrange(26):
		if len(Start[i]) > 1 or len(End[i]) > 1:
			flag = False
			break
	if not(flag):
		print 'Case #%d: 0' % (t)
		continue
	
	factor = 1
	for i in xrange(26):
		factor = (factor*Fact[len(Full[i])])%MOD
	
	JustFull = []
	for i in xrange(26):
		if ((Full[i] != []) and (Start[i] == []) and (End[i] == [])):
			JustFull.append(i)
	
	Edges = [None for i in xrange(N)]
	for i in xrange(26):
		for j in xrange(26):
			if Start[i] != [] and End[i] != []:
				Edges[End[i][0]] = Start[i][0]
	
	Visited = []
	for i in xrange(26):
		Visited.extend(Full[i])
	Visiting = []
	Components = 0
	
	for i in xrange(N):
		if i in Visited:
			continue
		Visiting = [i]
		while True:
			if Edges[Visiting[-1]] == None:
				Visited.extend(Visiting)
				Components += 1
				break
			if Edges[Visiting[-1]] in Visiting:
				#loop detected
				flag = False
				break
			if Edges[Visiting[-1]] in Visited:
				Visited.extend(Visiting)
				break
			Visiting.append(Edges[Visiting[-1]]) 
		if not(flag):
			break
	if not(flag):
		print 'Case #%d: 0' % (t)
		continue
	
	ans = (Fact[Components+len(JustFull)] * factor)%MOD
	
	print 'Case #%d: %d' % (t, ans)
	
#	Edges = []
#	for i in xrange(len(Strings)):
#		for j in xrange()
#	
#		
#	DP = [[[0 for i in xrange(26)] for i in xrange(26)] for i in xrange(N)]
#	
#	s = readline().split()
#	for i in xrange(N):
#		if valid(s[i]):
#			DP[0][ord(s[i][0])-ord('a')][ord(s[i][-1])-ord('a')] += 1
#	
#	for i in xrange(1, N):
#		for s in xrange(26):
#			for e in xrange(26):
#				for m in xrange(26):
#					if s == m and m == e:
#						DP[i][s][e] += DP[i-1][s][m] * (DP[i-1][m][e]-1)
#					else:
#						DP[i][s][e] += DP[i-1][s][m]*DP[i-1][m][e]
#	
#	ans = 0
#	for s in xrange(26):
#		for e in xrange(26):
#			ans += DP[N-1][s][e]
#	
#	for i in xrange(N):
#		for j in xrange(5):
#			for k in xrange(5):
#				print i, j, k, DP[i][j][k]
#	print 'Case #%d: %d' % (t, ans)
