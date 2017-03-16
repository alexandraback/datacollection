import sys, math

def solve(x, r, c):
	if r < c:
		r, c = c, r

	if x > 6:
		return 'RICHARD'
	if (r * c) % x != 0:
		return 'RICHARD'
	if x > r:
		return 'RICHARD'
	if int(math.ceil(x / 2.0)) > c:
		return 'RICHARD'
	if x == 4 and c == 2:
		return 'RICHARD'
	if x == 5 and c == 3 and r == 5:
		return 'RICHARD'
	if x == 6 and c == 3:
		return 'RICHARD'
	return 'GABRIEL'

def run():
	with open(sys.argv[1]) as f:
		n = int(f.readline())
		for i in range(n):
			line = f.readline()

			x, r, c = line.split()
			result = solve(int(x), int(r), int(c))
			print "Case #%d: %s" % (i+1, result)

run()
