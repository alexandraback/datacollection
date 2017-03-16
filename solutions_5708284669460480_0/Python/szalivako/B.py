import math
T = int(raw_input())
for ti in xrange(T):
	K, L, S = map(int, raw_input().split())
	Keyboard = raw_input()
	Word = raw_input()
	res = 0
	SF = K ** S
	#print SF
	index = []
	for i in range(S):
		index.append(0)
	maxN = 0
	while (index[-1] < K):
		#print index
		typed = ''
		for i in range(S):
			typed += Keyboard[index[i]]
		#print typed
		cnt = 0
		for i in range(S - L + 1):
			w = typed[i:i + L]
			if (w == Word):
				cnt += 1
		#print cnt
		if (cnt > maxN):
			maxN = cnt
		res += cnt*(float(1)/float(SF))
		i = 0
		while (i < S and index[i] == K - 1):
			index[i] = 0
			i += 1
		if (i == S):
			break
		else:
			index[i] += 1
	ans = maxN - res
	print 'Case #' + str(ti + 1) + ': ' + str(ans)