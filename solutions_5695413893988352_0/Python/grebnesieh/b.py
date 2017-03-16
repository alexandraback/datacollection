def isequal(a, b):
	for i, j in zip(a, b):
		if i == '?' or j == '?' or i == j:
			continue
		else:
			return False
	return True
for case in xrange(1, input() + 1):
	a, b = raw_input().split()
	l = len(a)
	ans = []
	for i in xrange(10 ** l):
		if isequal(str(i).zfill(l), a):
			for j in xrange(10 ** l):
				if isequal(str(j).zfill(l), b):
					ans.append([abs(i - j), i, j])
	ans.sort()
	print "Case #" + str(case) + ": " + str(ans[0][1]).zfill(l) + " " + str(ans[0][2]).zfill(l)