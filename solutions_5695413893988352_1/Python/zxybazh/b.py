def ld(s, n):
	s = '0' * (n - len(s)) + s
	return s

def solve(s):
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

	maxn1 = [0 for i in xrange(n + 10)]
	maxn2 = [0 for i in xrange(n + 10)]
	minn1 = [0 for i in xrange(n + 10)]
	minn2 = [0 for i in xrange(n + 10)]
	for i in xrange(n):
		t = n - i - 1
		if (s1[t] == '?'):
			maxn1[t] = 9 * 10 ** i + maxn1[t + 1]
			minn1[t] = minn1[t + 1]
		else:
			maxn1[t] = int(s1[t]) * 10 ** i + maxn1[t + 1]
			minn1[t] = int(s1[t]) * 10 ** i + minn1[t + 1]
		if (s2[t] == '?'):
			maxn2[t] = 9 * 10 ** i + maxn2[t + 1]
			minn2[t] = minn2[t + 1]
		else:
			maxn2[t] = int(s2[t]) * 10 ** i + maxn2[t + 1]
			minn2[t] = int(s2[t]) * 10 ** i + minn2[t + 1]

	mincha = 1e18
	minC   = 1e18
	minJ   = 1e18

	flag = "0"
	for i in xrange(n):
		if (s1[i] == s2[i]):
			if (s1[i] == '?'):
				C = int(flag) * 10 ** (n - i) + 10 ** (n - i - 1) + minn1[i+1]
				J = int(flag) * 10 ** (n - i) + maxn2[i+1]
				if (abs(C-J) < mincha or (abs(C-J) == mincha and C < minC) or (abs(C-J) == mincha and C == minC and J < minJ)):
					mincha = abs(C-J)
					minC = C
					minJ = J
				C = int(flag) * 10 ** (n - i) + maxn1[i+1]
				J = int(flag) * 10 ** (n - i) + 10 ** (n - i - 1) + minn2[i+1]
				if (abs(C-J) < mincha or (abs(C-J) == mincha and C < minC) or (abs(C-J) == mincha and C == minC and J < minJ)):
					mincha = abs(C-J)
					minC = C
					minJ = J
				flag += "0"
			else:
				flag += s1[i]
				continue
		else:
			if (s1[i] == '?'):
				C = int(flag) * 10 ** (n - i) + min(int(s2[i]) + 1, 9) * 10 ** (n - i - 1) + minn1[i+1]
				J = int(flag) * 10 ** (n - i) + int(s2[i]) * 10 ** (n - i - 1) + maxn2[i+1]
				if (abs(C-J) < mincha or (abs(C-J) == mincha and C < minC) or (abs(C-J) == mincha and C == minC and J < minJ)):
					mincha = abs(C-J)
					minC = C
					minJ = J
				C = int(flag) * 10 ** (n - i) + max(int(s2[i]) - 1, 0) * 10 ** (n - i - 1) + maxn1[i+1]
				J = int(flag) * 10 ** (n - i) + int(s2[i]) * 10 ** (n - i - 1) + minn2[i+1]
				if (abs(C-J) < mincha or (abs(C-J) == mincha and C < minC) or (abs(C-J) == mincha and C == minC and J < minJ)):
					mincha = abs(C-J)
					minC = C
					minJ = J
				flag += s2[i]
			elif (s2[i] == '?'):
				C = int(flag) * 10 ** (n - i) + int(s1[i]) * 10 ** (n - i - 1) + minn1[i+1]
				J = int(flag) * 10 ** (n - i) + max(int(s1[i]) - 1, 0) * 10 ** (n - i - 1) + maxn2[i+1]
				if (abs(C-J) < mincha or (abs(C-J) == mincha and C < minC) or (abs(C-J) == mincha and C == minC and J < minJ)):
					mincha = abs(C-J)
					minC = C
					minJ = J
				C = int(flag) * 10 ** (n - i) + int(s1[i]) * 10 ** (n - i - 1) + maxn1[i+1]
				J = int(flag) * 10 ** (n - i) + min(int(s1[i]) + 1, 9) * 10 ** (n - i - 1) + minn2[i+1]
				if (abs(C-J) < mincha or (abs(C-J) == mincha and C < minC) or (abs(C-J) == mincha and C == minC and J < minJ)):
					mincha = abs(C-J)
					minC = C
					minJ = J
				flag += s1[i]
			else:
				if (s1[i] > s2[i]):
					C = int(flag) * 10 ** (n - i) + int(s1[i]) * 10 ** (n - i - 1) + minn1[i+1]
					J = int(flag) * 10 ** (n - i) + int(s2[i]) * 10 ** (n - i - 1) + maxn2[i+1]
				else:
					C = int(flag) * 10 ** (n - i) + int(s1[i]) * 10 ** (n - i - 1) + maxn1[i+1]
					J = int(flag) * 10 ** (n - i) + int(s2[i]) * 10 ** (n - i - 1) + minn2[i+1]
				if (abs(C-J) < mincha or (abs(C-J) == mincha and C < minC) or (abs(C-J) == mincha and C == minC and J < minJ)):
					mincha = abs(C-J)
					minC = C
					minJ = J
				break
	print ld(str(minC), n), ld(str(minJ), n)
		

file = open("B-large.in", "r")
a = file.readlines()
for i in xrange(1, len(a)):
	print "Case #%d:" % i,
	solve(a[i])
'''
solve("??9 6?1")
'''