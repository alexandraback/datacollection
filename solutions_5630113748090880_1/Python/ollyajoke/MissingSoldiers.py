def findMissingLine(M):
	d = {}
	for m in M:
		for i in m:
			d[i] = d.get(i, 0) + 1
	res = []
	for k in d:
		if d[k]%2 != 0:
			res.append(k)
	res = map(str, sorted(res))
	return " ".join(res)

T = int(raw_input().strip())
for i in range(0, T):
	N = int(raw_input().strip())
	M = []
	for j in range(0, 2*N-1):
		m = map(int, raw_input().strip().split(" "))
		M.append(m)
	print 'Case #' + str(i+1) + ':', findMissingLine(M)