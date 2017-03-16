import sys

def getMax(n, s, p, scores) :
	res = 0
	for score in scores :
		x = int(score) / 3
		y = int(score) % 3
		if y == 0 :
			if x >= p :
				res += 1
			elif x > 0 and s > 0 and x + 1 >= p :
				res += 1
				s -= 1
		elif y == 1 :
			if x + 1 >= p :
				res += 1
		else :
			if x + 1 >= p :
				res += 1
			elif s > 0 and x + 2 >= p :
				res += 1
				s -= 1
	return res


t = int(sys.stdin.readline())

for i in range(t) :
	line = sys.stdin.readline().strip().split()
	n = int(line[0])
	s = int(line[1])
	p = int(line[2])
	scores = line[3:]
	print "Case #%d:" % (i+1), getMax(n, s, p, scores)