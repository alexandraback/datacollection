def test(bv, n, m):
	br = set()
	bc = set()
	i = n*m-1
	while i >= 0:
		j = i
		while j >= 0 and bv[j][0] == bv[i][0]:
			if bv[j][1] in br and bv[j][2] in bc:
				return False
			j -= 1
		while i > j:
			br.add(bv[i][1])
			bc.add(bv[i][2])
			i -= 1
		#print br, bc
	return True
t = int(raw_input())
for _ in range(1, t+1):
	n, m = map(int, raw_input().split())
	bv = list()
	for i in range(n):
		row = map(int, raw_input().split())
		for j in range(m):
			bv.append((row[j], i, j))
	bv.sort()
	#print bv
	if test(bv, n, m):
		print 'Case #%d: YES' % _
	else:
		print 'Case #%d: NO' % _
