from operator import attrgetter

class Level:
	def __init__(self, a, b):
		self.a = a
		self.b = b
		self.remaining = 2
	
	def __str__(self):
		return "{0} {1}: {2}".format(self.a, self.b, self.remaining)

T = int(raw_input())
for t in range(1, T+1):
	N = int(raw_input())
	levels = []
	for i in range(N):
		a, b = map(int, raw_input().split())
		levels.append(Level(a, b))
	levels = sorted(levels, key=attrgetter('b', 'a'), reverse=True)
	
	stars = 0
	times = 0
	while stars < 2 * N:
		times += 1
		cont = False
		for lvl in levels:
			if stars >= lvl.b and lvl.remaining > 0:
				stars += lvl.remaining
				lvl.remaining = 0
				cont = True
				break
		if cont:
			continue
		for lvl in levels:
			if stars >= lvl.a and lvl.remaining == 2:
				stars += 1
				lvl.remaining = 1
				cont = True
				break
		if not cont:
			break
	
	print "Case #{0}: {1}".format(t, times if stars == 2*N else "Too Bad")
