import sys,itertools
inp = """2
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600"""
if len(sys.argv) > 1:
	inp = open(sys.argv[1]).read().strip()
inp = inp.split("\n")
ind = 1
for l in inp[1:]:
	l = l.strip().split(" ")[1:]
	l = [int(x) for x in l]
	print "Case #%s:"%(ind)
	found = False
	for i in range(1, len(l)):
		for c in itertools.combinations(l, i):
			c = set(c)
			for i2 in range(1, len(l)):
				for c2 in itertools.combinations(l, i):
					c2 = set(c2)
					if c == c2:
						continue
					if sum(c) == sum(c2):
						print " ".join([str(x) for x in c])
						print " ".join([str(x) for x in c2])
						found = True
						break
				if found:
					break
			if found:
				break
		if found:
			break
	if not found:
		print "Impossible"
	ind += 1