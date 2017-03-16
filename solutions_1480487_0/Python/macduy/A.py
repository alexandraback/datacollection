INPUT = {
	'data': ('int', 'linearray')
}

TEST = ('''\
6
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21
3 2 10 1
7 1 5 1 1 1 1 10
''','''\
Case #1: 33.333333 66.666667
Case #2: 0.000000 100.000000
Case #3: 25.0 25.0 25.0 25.0
Case #4: 34.666667 26.666667 38.666667
Case #5: 0.461538 0.538462
Case #6: 0.461538 0.538462
''')

def main(data):
	N, points = data[0], data[1:]
	total = sum(points)
	
	sorted_points = sorted(points)
	
	margins = []
	rest = total;
	for i in xrange(0, N-1):
		diff = (sorted_points[i+1] - sorted_points[i])
		if diff * (i + 1) > rest:
			# too much to distribute
			diff = float(rest) / (i + 1)
			margins.append(diff)
			rest = 0
		else:
			rest -= diff * (i + 1)
			margins.append(diff)
	
	margins.append(float(rest) / N)	
	margins.reverse()
	cum_margins = []
	csum = 0
	for m in margins:
		csum += m
		cum_margins.append(csum)
	margins.reverse()
	cum_margins.reverse()

	
	# find last index of
	res = []
	for p in points:
		i = sorted_points.index(p)
		while (i < N - 1 and sorted_points[i + 1] == p):
			i += 1
		prc = float(cum_margins[i]) / total
		res.append(prc if prc > 0 else 0)
	
	print margins
	print cum_margins
	print sum(cum_margins), total
	
	return ' '.join(map(lambda x: '%.8f' % (x * 100), res))