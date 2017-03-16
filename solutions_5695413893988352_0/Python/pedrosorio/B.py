def solve(C, J):
	cs = [c for c in C]
	js = [c for c in J]
	gt = 0
	for i in xrange(len(cs)):
		if cs[i] != '?' and js[i] != '?':
			pg = i
			gt = ord(cs[i]) - ord(js[i]) 
	for i in xrange(len(cs)):
		if cs[i] == '?' and js[i] == '?':
			if gt > 0:
				cs[i] = '0'
				js[i] = '9'
			elif gt < 0:
				cs[i] = '9'
				js[i] = '0'
			else:
				cs[i] = '0'
				js[i] = '0'
		elif cs[i] == '?':
			if gt > 0:
				cs[i] = '0'
			elif gt < 0:
				cs[i] = '9'
			else:
				cs[i] = js[i]
		elif js[i] == '?':
			if gt > 0:
				js[i] = '9'
			elif gt < 0:
				js[i] = '0'
			else:
				js[i] = cs[i]
	return ''.join(cs) + ' ' + ''.join(js)


def solve_small(C, J):
	ct = len([c for c in C if c == '?']) + len([c for c in J if c == '?'])
	mx = 10**ct
	minabs, minc, minj = 10**10, 10**10, 10**10 
	rc, rj = [c for c in C], [c for c in J]
	for vv in xrange(mx):
		v = vv
		cs = [c for c in C]
		js = [c for c in J]
		cv, jv = 0, 0
		for i in xrange(len(cs)):
			if cs[i] == '?':
				cs[i] = v % 10
				v /= 10
			cv = cv * 10 + int(cs[i])
		for i in xrange(len(js)):
			if js[i] == '?':
				js[i] = v % 10
				v /= 10
			jv = jv * 10 + int(js[i])
		abd = abs(cv - jv)
		if abd <= minabs:
			if abd == minabs:
				if cv > minc:
					continue
				if cv == minc:
					if jv > minj:
						continue
			minabs, minc, minj = abd, cv, jv
			rc = [c for c in cs]
			rj = [c for c in js]
	return ''.join(map(str, rc)) + ' ' + ''.join(map(str, rj))


T = int(raw_input())
for case in range(1, T+1):
	C, J = raw_input().split()
	print "Case #{}: {}".format(case, str(solve_small(C, J)))