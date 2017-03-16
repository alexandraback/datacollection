class Sub:
	def __init__(self, array, e):
		self.a = array
		self.e = e
	def __call__(self, i):
		return self.a[i][self.e]

def solve(stars):
	s = 0
	total = 0
	levels = 0
	while len(stars) > 0:
		mi = min((j for j in xrange(len(stars))), key=Sub(stars, 1))
		for j in xrange(1, len(stars)):
			if stars[j][1] <= total and stars[j][0] > stars[mi][0]:
				mi = j
		if stars[mi][1] <= total:
			if stars[mi][0] == float('inf'):
				total += 1
			else:
				total += 2
			levels += 1
			stars = stars[:mi] + stars[mi + 1:]
		else:
			mi = min((j for j in xrange(len(stars))), key=Sub(stars, 0))
			#mi = max((j for j in xrange(len(stars)) if stars[j][0] == stars[mi][0]), key=Sub(stars, 1))
			for j in xrange(1, len(stars)):
				if stars[j][0] <= total and stars[j][1] > stars[mi][1]:
					mi = j
			if stars[mi][0] <= total:
				stars[mi][0] = float('inf')
				total += 1
				levels += 1
			else:
				break
	if len(stars) > 0:
		return "Too Bad"
	return levels
		

def main():
	T = int(raw_input()) # num test cases
	for case in xrange(1, T + 1):
		n = int(raw_input())
		s = []
		for j in xrange(n):
			s.append([int(d) for d in raw_input().split()])
		#print s
		print "Case #%d: %s" % (case, solve(s))

if __name__ == "__main__":
	main()

