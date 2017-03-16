def solve(K, C, S):
	if K == 1:
		return "1" 
	grads = []
	checking = 0
	while checking < K:
		checking += 1
		comp = 1
		pos = checking
		while comp < C and checking < K:
			comp += 1
			pos = (pos-1) * K + checking + 1
			checking += 1
		grads.append(pos)
	if len(grads) > S:
		return "IMPOSSIBLE"
	return ' '.join(map(str, grads))


T = int(raw_input())
for case in range(1, T+1):
	K, C, S = map(int, raw_input().split())
	print "Case #{}: {}".format(case, str(solve(K, C, S)))