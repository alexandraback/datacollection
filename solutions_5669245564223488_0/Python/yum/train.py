import itertools
cases = int(input())
for tc in range(cases):
	input()
	oldstrs = input().split()
	strs = []
	for os in oldstrs:
		ns = ""
		pc = -1
		for c in os:
			if c == pc: continue
			ns += c
			pc = c
		strs.append(ns)
	ways = 0
	for p in itertools.permutations(strs, len(strs)):
		seen = set()
		s = ''.join(p)
		fail = False
		for c in s:
			if c not in seen:
				seen.add(c)
			elif c != pc:
				fail = True
				break
			pc = c
		if not fail:
			ways += 1
	print("Case #%d: %d" % (tc+1, ways))
