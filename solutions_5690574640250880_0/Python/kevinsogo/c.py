def adj(g):
	return ['c' + ''.join(g[0][1:])] + g[1:]

def f(r, c, s):
	if r > c:
		g = f(c, r, s)
		if g is not None: g = zip(*g)
		return g
	if s == 1:    return ['*'*c]*r
	if s == r*c:  return ['.'*c]*r
	if r == 1:    return ['.'*s + '*'*(c-s)]
	if s == 2:    return None
	if r == 2:
		if s & 1: return None
		return ['.'*(s/2) + '*'*(c-s/2)]*2
	if s == 4: return ['..' + '*'*(c-2)]*2 + ['*'*c]*(r-2)
	if s == 6: return ['...' + '*'*(c-3)]*2 + ['*'*c]*(r-2)
	if s == 8: return ['...' + '*'*(c-3)]*2 + ['..' + '*'*(c-2)] + ['*'*c]*(r-3)
	if s == 9: return ['...' + '*'*(c-3)]*3 + ['*'*c]*(r-3)
	if s < 10: return None
	if s <= 3*c:
		if s % 3 == 0: return ['.'*(s/3) + '*'*(c-s/3)]*3 + ['*'*c]*(r-3)
		if s % 3 == 1: return ['.'*(s/3+1) + '*'*(c-s/3-1)]*2 + ['.'*(s/3-1) + '*'*(c-s/3+1)] + ['*'*c]*(r-3)
		if s % 3 == 2: return ['.'*(s/3+1) + '*'*(c-s/3-1)]*2 + ['.'*(s/3) + '*'*(c-s/3)] + ['*'*c]*(r-3)
	if s % c == 1: return ['.'*c]*(s/c-1) + ['.'*(c-1) + '*', '..' + '*'*(c-2)] + ['*'*c]*(r-s/c-1)
	return ['.'*c]*(s/c) + ['.'*(s%c) + '*'*(c-s%c)] + ['*'*c]*(r-s/c-1)

for cas in xrange(1,input()+1):
	print "Case #%s:" % cas
	r, c, m = map(int, raw_input().strip().split())
	ans = f(r, c, r*c-m)
	if ans is None:
		print "Impossible"
	else:
		print '\n'.join(''.join(x) for x in adj(ans))
