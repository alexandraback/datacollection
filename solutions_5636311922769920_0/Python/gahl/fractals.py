# (k**c/k)
# XYZ
# XXXYYYZZZ
# XXXXXXXXXYYYYYYYYYZZZZZZZZZ
# ^         ^         ^

def get_fractal_locations(k, c, s):
	l = []
	if c == 1:
		return range(1, k+1)
	step = k**(c-1)
	for i in xrange(s):
		l.append(step*i + i + 1) # + 1 because 1 based
	return l

def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		k, c, s = [int(a) for a in raw_input().split(' ')]
		locations = get_fractal_locations(k, c, s)
		print "Case #%d: %s" % (x + 1, ' '.join(str(a) for a in locations))

main()