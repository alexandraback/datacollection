T = int(raw_input())

def solve(K, C, S):
	if float(K)/C > S:
		return 'IMPOSSIBLE'

	indices = []

	for k in range(0, K, C):
		spots = range(k, min(k+C, K))
		index = 0
		for i, spot in enumerate(spots):
			index += spot * K**i
		indices += [str(index+1)]
	return str.join(' ', indices)

for t in range(1, T+1):
	[K, C, S] = [int(i) for i in raw_input().split()]
	print "Case #%d: %s" % (t, solve(K, C, S))