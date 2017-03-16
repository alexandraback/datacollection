import sys, math

cache = {}

def move(pi):
	if pi < 3:
		return pi
	elif pi in cache:
		return cache[pi]
	else:
		s = []
		for i in range(1, int(math.ceil(pi / 2.0))):
			pimax = int(math.ceil(pi / (i+1.0)))
			s.append(move(pimax) + i)
		cache[pi] = min(s)
		return cache[pi]

def solve(p):
	s = [move(pi) for pi in p]
	return max(s)

def run():
	with open(sys.argv[1]) as f:
		n = int(f.readline())
		for i in range(n):
			line1 = f.readline()
			line2 = f.readline()

			d = int(line1)
			p = [int(pi) for pi in line2.split()]
			assert d == len(p)
			result = solve(p)
			print "Case #%d: %d" % (i+1, result)

for i in range(1000):
	move(i)
run()
