infile = open('C-small-attempt1 (1).in', 'r')
outfile = open('test.out', 'w')

T = int(infile.readline())

for t in range(T):
	N = int(infile.readline())
	ids = map(int, infile.readline().strip().split(' '))
	bffs = {}
	for i in range(1, N+1):
		bffs[i] = ids[i-1]
	circles = []
	for i in bffs:
		tmp = [i]
		while bffs[i] not in tmp:
			tmp.append(bffs[i])
			i = bffs[i]
		something = True
		ok = True
		if len(tmp) < 2:
			pass
		elif bffs[tmp[-1]] != tmp[-2] and bffs[tmp[-1]] != tmp[0]:
			ok = False
		while something:
			something = False
			if tmp[0] in bffs.itervalues() and (bffs[tmp[0]] != tmp[-1] and bffs[tmp[-1]] != tmp[0]):
				for i in range(1, N+1):
					if bffs[i] == tmp[0] and i not in tmp:
						tmp = [i] + tmp
						something = True
						break
			elif tmp[-1] in bffs.itervalues() and (bffs[tmp[0]] != tmp[-1] and bffs[tmp[-1]] != tmp[0]):
				for i in range(1, N+1):
					if bffs[i] == tmp[-1] and i not in tmp:
						tmp += [i]
						something = True
						break
		if ok:
			circles.append(tmp)
	ans = max(map(len, circles))
	outfile.write('Case #' + str(t+1) + ': ' + str(ans) + '\n')