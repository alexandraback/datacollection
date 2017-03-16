mult_table = [[0, 1, 2, 3, 4, 5, 6, 7], # 0 -> 1
			  [1, 0, 3, 2, 5, 4, 7, 6], # 1 -> -1
			  [2, 3, 1, 0, 6, 7, 5, 4], # 2 -> i
			  [3, 2, 0, 1, 7, 6, 4, 5], # 3 -> -i
			  [4, 5, 7, 6, 1, 0, 2, 3], # 4 -> j
			  [5, 4, 6, 7, 0, 1, 3, 2], # 5 -> -j
			  [6, 7, 4, 5, 3, 2, 1, 0], # 6 -> k
			  [7, 6, 5, 4, 2, 3, 0, 1]] # 7 -> -k
equiv = {'i': 2, 'j': 4, 'k': 6}

def check(L, X, s):
	cur = 0
	for pos in xrange(min(L * X, L * 4)):
		if cur == 2:
			break
		cur = mult_table[cur][s[pos % L]]
	if cur != 2:
		return 'NO'
	cur = 0
	for pos in xrange(pos, min(L * X, pos + L * 4)):
		if cur == 4:
			break
		cur = mult_table[cur][s[pos % L]]
	if cur != 4:
		return 'NO'
	cur = 0
	for pos in xrange(pos, pos + ((L * X - pos) % (L * 4))):
		cur = mult_table[cur][s[pos % L]]
	if cur != 6:
		return 'NO'
	return 'YES'

T = int(raw_input())

for test in xrange(T):
	L, X = [int(i) for i in raw_input().split()]
	s = [equiv[i] for i in raw_input()]
	print "Case #{}: {}".format(test + 1, check(L, X, s))