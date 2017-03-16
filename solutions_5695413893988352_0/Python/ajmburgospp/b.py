from itertools import product
T = int(raw_input())
for kei in xrange(1, T+1):
	c, j = raw_input().split()
	qs = sum(1 for i in c+j if i == '?')
	absdiff = 1000
	minj = 1000
	pos = [xrange(10)]*qs

	for psol in product(*pos):
		comb = c+","+j
		comb = comb.replace('?', '{}')
		comb = comb.format(*psol)
		sc, sj = comb.split(',')
		tc, tj = int(sc), int(sj)
		if abs(tc-tj) < absdiff:
			nc, nj = sc, sj
			absdiff = abs(tc-tj)
			minj = tj
	print "Case #{}: {} {}".format(kei, nc, nj)
	# solc = []
	# solj = []
	# status = 0
	# for i in xrange(len(c)):
	# 	if status < 0:
	# 		if c[i] == '?'
	# 	elif status > 0:
	# 	else:
	# 		if c[i] == '?' and j[i] == '?':
	# 			solc.append('0')
	# 			solj.append('0')
	# 		elif c[i] == '?':
	# 			solc.append(j[i])
	# 			solj.append(j[i])
	# 		elif c[j] == '?':
	# 			solc.append(c[i])
	# 			solj.append(c[i])
	# 		else:
	# 			status = ord(c[i]) - ord(j[i])
	# 			solc.append(c[i])
	# 			solj.append(j[i])
	# print "Case #{}: {} {}".format(kei, ''.join(solc), ''.join(solj))