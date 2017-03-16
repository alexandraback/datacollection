def solve(b):
	# b = ['a b', 'a c', 'a d', 'e b', 'e c', 'f d']
	a = []
	for s in b:
		while s.endswith("\r") or s.endswith("\n"):
			s = s[:-1]
		a.append(s.split(" "))
	s1 = {}
	s2 = {}
	for t in a:
		if t[0] in s1: s1[t[0]] += 1
		else: s1[t[0]] = 1
		if t[1] in s2: s2[t[1]] += 1
		else: s2[t[1]] = 1
	for i in xrange(len(a)):
		for j in xrange(i):
			if (s1[a[j][0]] > s1[a[i][0]] or (s1[a[j][0]] == s1[a[i][0]] and s2[a[j][1]] > s2[a[i][1]])):
				tmp = a[i][0]
				a[i][0] = a[j][0]
				a[j][0] = tmp
				tmp = a[i][1]
				a[i][1] = a[j][1]
				a[j][1] = tmp
	s1 = {}
	s2 = {}
	cnt = 0
	# print a
	for w in a:
		if (w[0] in s1 and w[1] in s2):
			cnt += 1
		s1[w[0]] = 1
		s2[w[1]] = 1
	print cnt

file = open("C-small-attempt0.in", "r")
a = file.readlines()
T = int(a[0])
line = 1
for i in xrange(T):
	print "Case #%d:" % (i+1), 
	b = []
	k = int(a[line])
	line += 1
	for j in xrange(k):
		b.append(a[line])
		line += 1
	solve(b)
