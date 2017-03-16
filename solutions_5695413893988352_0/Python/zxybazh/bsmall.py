s1 = ""
s2 = ""
u = []
mincha = 1e9
minC = 1e9
minJ = 1e9

def dfs(n):
	global s1, s2, u, mincha, minJ, minC
	if (n > 0):
		for i in xrange(10):
			u.append(i)
			dfs(n-1)
			u = u[:-1]
	else:
		ts1 = s1
		ts2 = s2
		for i in u:
			if ("?" in s1):
				s1 = s1[:s1.find('?')] + str(i) + s1[s1.find('?')+1:]
			else:
				s2 = s2[:s2.find('?')] + str(i) + s2[s2.find('?')+1:]
		s1 = int(s1)
		s2 = int(s2)
		if (abs(s1-s2) < mincha or (abs(s1-s2) == mincha and s1 < minC) or (abs(s1-s2) == mincha and s1 == minC and s2 < minJ)):
			mincha = abs(s1-s2)
			minC = s1
			minJ = s2
		s1 = ts1
		s2 = ts2

def ld(s, n):
	s = '0'*(n - len(s)) + s
	return s
		
def solve(s):
	global s1, s2, u, mincha, minJ, minC
	mincha = 1e9
	minC = 1e9
	minJ = 1e9
	while s.endswith("\r") or s.endswith("\n"):
		s = s[:-1]
	s1, s2 = s.split(" ")[:2]
	n = len(s1)
	flag = ""
	for i in xrange(n):
		if (s1[i] == s2[i]):
			if (s1[i] == '?'): flag += "0"
			else: flag += s1[i]
		else:
			if (s1[i] == '?'): flag += s2[i]
			elif (s2[i] == '?'): flag += s1[i]
			else:
				flag = ""
				break
	if (flag != ""):
		print flag, flag
		return
	
	cnt = 0
	for w in s1 + s2:
		if (w == '?'): cnt += 1
	dfs(cnt)
	print ld(str(minC), n), ld(str(minJ), n)
	

file = open("B-small-attempt0.in", "r")
a = file.readlines()
for i in xrange(1, len(a)):
	print "Case #%d:" % i,
	solve(a[i])
