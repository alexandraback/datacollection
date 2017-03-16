import itertools
for i in range(input()):
	n = input()
	f = [int(x) - 1 for x in raw_input().split()]
	best = 0
	for m in range(1, n + 1):
		for c in itertools.combinations(range(n), m):
			ok = 1
			for j in range(m):
				if f[c[j]] not in c:
					ok = 0
					break
			if not ok: continue
			l = [c[0], f[c[0]]]
			c = set(c) - set(l)
			for p in itertools.permutations(c):
				ok = 1
				a = l + list(p)
				for j in range(m):
					if f[a[j]] != a[(j + m - 1) % m] and f[a[j]] != a[(j + 1) % m]:
						ok = 0
						break
				if ok:
					best = m
					break
			if best == m: break
	print "Case #" + str(i + 1) + ": " + str(best)
