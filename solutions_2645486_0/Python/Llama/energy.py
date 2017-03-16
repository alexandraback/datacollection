def solve(e, r, n ,v, state, i):
	#print i, state
	if i==n:
		return state[min(r,e)]
	new_state = {}
	for e0, p0 in state.items():
		for ed in range(0, e0+1):
			e1 = min(e0 - ed + r, e)
			p1 = p0 + ed * v[i]
			if e1 in new_state and new_state[e1]>p1:
				pass
			else:
				new_state[e1] = p1
	return solve(e, r, n, v, new_state, i+1)


k = int(raw_input())
for i in range(0, k):
	e, r, n = [int(x) for x in raw_input().split()]
	v = [int(x) for x in raw_input().split()]
	state = {e:0}
	#print i, e, r ,n, v
	result = solve(e, r, n, v, state, 0)
	print 'Case #%s: %s' % (i+1, result)