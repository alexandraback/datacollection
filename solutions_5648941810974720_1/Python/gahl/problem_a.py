import copy

letters = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
special = {'Z': 0, 'X': 6, 'W': 2, 'U': 4}

def preproc(s):
	d = {}
	for a in xrange(ord('A'), ord('Z') + 1):
		d[chr(a)] = 0

	for a in s:
		d[a] += 1

	return d

def remove_from_dict(d, num, mult = 1):
	check = True

	for a in letters[num]:
		if d[a] < mult:
			check = False
			break

	if check == False:
		return False
	
	for a in letters[num]:
		d[a] -= mult

	return True

def add_to_dict(d, num, mult = 1):
	for a in letters[num]:
		d[a] += mult

def recurse_solv(ds, total):
	if total == 0:
		return []
	for a in xrange(10):
		if remove_from_dict(ds, a):
			x = recurse_solv(ds, total - len(letters[a]))
			if x != None:
				return x + [a]
			add_to_dict(ds, a)
	return None

def one(s):
	d = {}
	for a in xrange(10):
		d[a] = 0

	ds = preproc(s)
	for k,v in special.iteritems():
		d[v] = ds[k]
		remove_from_dict(ds, v, ds[k])

	total = sum(v for k,v in ds.iteritems())

	final = recurse_solv(ds, total)
	for a in final:
		d[a] += 1

	final = [str(k)*v for k,v in d.iteritems() if v > 0]
	final.sort()
	return ''.join(final)

def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		num = raw_input()
		print "Case #%d: %s" % (x + 1, one(num))

main()