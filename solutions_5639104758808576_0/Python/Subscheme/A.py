getl = lambda: raw_input().split()
get = lambda: map(int, getl())

T, = get()

for testCase in range(1, T+1):
	_, v = getl()
	extra = 0
	standing = 0
	for c in map(int, v):
		standing += c - 1
		if standing < 0:
			extra += 1
			standing += 1
	print "Case #%d: %d" % (testCase, extra)