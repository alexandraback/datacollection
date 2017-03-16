for case in range(1, int(input())+1):
	(K, C, S) = map(int,input().split())
	if (S * C) < K:
		result = 'IMPOSSIBLE'
	else:
		tiles = []
		if C > K:
			C = K
		exp = C
		tile = 0
		for x in range(0, K):
			exp -= 1
			tile += x * (K ** exp)
			if exp == 0:
				tiles.append(tile + 1)
				tile = 0
				exp = C
		if exp != C:
			tiles.append(tile + 1)
		result = ' '.join(map(str,tiles))
	print ("Case #%d: %s" % (case, result))

