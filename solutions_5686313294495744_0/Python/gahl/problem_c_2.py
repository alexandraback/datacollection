
def mifkad(x):
	d = {}
	for a in x:
		if a in d:
			d[a] += 1
		else:
			d[a] = 1
	return d

def recurse_solve(kuf, kus, remaining, only_to_test=[]):
	num = 0
	nr = []
	for r in remaining:
		if r[0] in kuf and r[1] in kus:
			num += 1
		else:
			nr.append(r)

	for r in only_to_test:
		if r[0] in kuf and r[1] in kus:
			num += 1

	so_far = 0
	for i, a in enumerate(nr):
		to_rem_0 = False
		to_rem_1 = False
		if a[0] not in kuf:
			kuf.add(a[0])
			to_rem_0 = True
		if a[1] not in kus:
			kus.add(a[1])
			to_rem_1 = True
		res = recurse_solve(kuf, kus, nr[i+1:], nr[:i])
		if res > so_far:
			so_far = res

		if to_rem_0:
			kuf.remove(a[0])
		if to_rem_1:
			kus.remove(a[1])
	return so_far + num

def one(lines):
	p = [x.split(' ') for x in lines]
	first = mifkad(a[0] for a in p)
	second = mifkad(a[1] for a in p)

	unique = []
	np = []
	for l in p:
		if first[l[0]] == 1 or second[l[1]] == 1:
			unique.append(l)
		else:
			np.append(l)

	p, np = np, []
	if len(p) == 0:
		return 0

	existing_f = set(a[0] for a in unique)
	existing_s = set(a[1] for a in unique)

	best = 0
	for MASK in xrange(0, 2**len(p)):
		sf = set()
		ss = set()
		i = 0
		to_check = []
		while MASK > 0:
			if MASK & 1 == 1:
				sf.add(p[i][0])
				ss.add(p[i][1])
			else:
				to_check.append(p[i])
			MASK >>= 1
			i += 1
		if i < len(p):
			to_check += p[i:]

		ok = True
		for r in to_check:
			if (r[0] in sf or r[0] in existing_f) and (r[1] in ss or r[1] in existing_s):
				continue
			else:
				ok = False
				break
		if ok:
			best = max(best, len(to_check))
	return best






def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):

		num = int(raw_input())
		lines = [raw_input() for a in xrange(num)]
		print "Case #%d: %s" % (x + 1, one(lines))

main()