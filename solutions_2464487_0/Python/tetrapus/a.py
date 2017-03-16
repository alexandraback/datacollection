import sys
data = open(sys.argv[1]).read().split("\n")

cases = int(data.pop(0))
for case in range(cases):
	print "Case #%d:" % (case + 1),
	r, t = map(int, data.pop(0).split())
	rings = 0
	while t >= (r+1)**2 - r**2:
		t -= (r+1)**2 - r**2
		r += 2
		rings += 1
	print rings
