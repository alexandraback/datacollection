import sys

input = sys.stdin
output = sys.stdout

T = int(input.readline())
for t in range(T):
	line = [float(i) for i in input.readline().strip().split(' ')]
	N = line[0]
	points = line[1:]
	s = sum(points)
	r = s
	losers = []
	for p in points:
		if p < 2 * s / N:
			losers.append(p)
	m = max(losers)
	for p in losers:
		r -= m - p

	print 'Case #{t}:'.format(t = t + 1),
	for p in points:
		if p < 2 * s / N:
			v = (m - p + r / len(losers)) * 100 / s
		else:
			v = 0
		print '{}'.format(round(v, 8)),
#		print '{}'.format(round(max(200 / N - 100 * p / s, 0), 8)),
	print
