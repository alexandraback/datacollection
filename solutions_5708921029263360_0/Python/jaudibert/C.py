import itertools

def make_outfits(j, p, s, k):
	jp = {}
	ps = {}
	js = {}
	jps = {}
	outfits = []
	for x in range(j, 0, -1):
		for y in range(p, 0, -1):
			for z in range(s, 0, -1):
				outfit = "%d %d %d" % (x, y, z)
				# print outfit
				jpComb = "%d %d" % (x, y)
				psComb = "%d %d" % (y, z)
				jsComb = "%d %d" % (x, z)
				if outfit in jps:
					# print "repeat"
					continue
				if jpComb in jp:
					if jp[jpComb] == k:
						# print jpComb
						continue
				if jsComb in js:
					if js[jsComb] == k:
						# print jsComb
						continue
				if psComb in ps:
					if ps[psComb] == k:
						# print psComb
						continue

				outfits.append(outfit)
				jps[outfit] = 1
				if jpComb in jp:
					jp[jpComb] = jp[jpComb] + 1
				else:
					jp[jpComb] = 1
				if jsComb in js:
					js[jsComb] = js[jsComb] + 1
				else:
					js[jsComb] = 1
				if psComb in ps:
					ps[psComb] = ps[psComb] + 1
				else:
					ps[psComb] = 1
	return outfits

def main():
	# take in input

	t = int(raw_input())

	solutions = []

	for i in range(t):
		l = map(int, raw_input().split())
		j, p, s, k = l

		outfits = make_outfits(j, p, s, k)

		solutions.append("Case #" + str(i+1) + ": " + str(len(outfits)))
		for outfit in outfits:
			solutions.append(outfit)

	for solution in solutions:
		print solution


if __name__ == "__main__":
	main()