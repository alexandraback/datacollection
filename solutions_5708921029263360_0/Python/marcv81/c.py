def solver(J, P, S, K):
	jp = {}
	js = {}
	ps = {}
	outfits = []
	for s in xrange(1, S + 1):
		for p in xrange(1, P + 1):
			for j in xrange(1, J + 1):
				jp_key = str(j) + ' ' + str(p)
				js_key = str(j) + ' ' + str(s)
				ps_key = str(p) + ' ' + str(s)
				if jp_key not in jp:
					jp[jp_key] = 0
				if js_key not in js:
					js[js_key] = 0
				if ps_key not in ps:
					ps[ps_key] = 0
				if jp[jp_key] < K and js[js_key] < K and ps[ps_key] < K:
					outfits.append(str(j) + ' ' + str(p) + ' ' + str(s))
					jp[jp_key] += 1
					js[js_key] += 1
					ps[ps_key] += 1
	return outfits

with open('C-small-attempt1.in', 'r') as f:
	tc_len = int(f.readline().strip())
	for tc in xrange(1, tc_len + 1):
		(J, P, S, K) = tuple(int(i) for i in f.readline().strip().split())
		outfits = solver(J, P, S, K)
		print 'Case #' + str(tc) + ': ' + str(len(outfits))
		for outfit in outfits:
			print outfit
