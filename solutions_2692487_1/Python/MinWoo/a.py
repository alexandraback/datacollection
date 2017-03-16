
def solve(A, motes):
	motes.sort()
	N = len(motes)
	table = [[] for _ in xrange(N+1)]
	table[0] = [(0, A)]
	for i in xrange(N):
		for x in table[i]:
			if x[1] > motes[i]:
				table[i+1].append((x[0], x[1]+motes[i]))
			else:
				table[i+1].append((x[0]+1, x[1]))
				a, b = x
				if b > 1:
					while b <= motes[i]:
						b += b - 1
						a += 1
					table[i+1].append((a,b+motes[i]))
	#print table[N]
	return min(table[N])[0]

T = input()
for tc in xrange(T):
	A, N = map(int, raw_input().split())
	motes = map(int, raw_input().split())
	print 'Case #%d: %d' % (tc+1, solve(A, motes))

