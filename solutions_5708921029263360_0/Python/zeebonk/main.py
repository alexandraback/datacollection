import fileinput
from itertools import product
from collections import Counter


def main():
	stream = fileinput.input()
	cases = int(next(stream))
	for case in xrange(cases):
		jackets_c, pants_c, shirts_c, max_repeats = map(int, next(stream).strip().split(' '))
		outfits = Counter()
		bla = []
		jps = Counter()
		jss = Counter()
		pss = Counter()
		for outfit in product(xrange(shirts_c), xrange(pants_c), xrange(jackets_c)):
			if outfit in outfits:
				continue
			shirt, pants, jacket = outfit
			jp = (jacket, pants)
			if jps[jp] >= max_repeats:
				continue
			js = (jacket, shirt)
			if jss[js] >= max_repeats:
				continue
			ps = (pants, shirt)
			if pss[ps] >= max_repeats:
				continue

			outfits[outfit] += 1
			jps[jp] += 1
			jss[js] += 1
			pss[ps] += 1
			bla.append(outfit)

		print "Case #%d: %s" % (case + 1, len(bla))
		for x in bla:
			x = [i + 1 for i in x]
			print ' '.join(map(str, x))


if __name__ == '__main__':
	main()
