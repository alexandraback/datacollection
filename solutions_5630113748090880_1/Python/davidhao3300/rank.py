def find_index(pos, val, grid):
	res = []
	for row in grid:
		if row[pos] == val:
			res.append(row)
	return res

with open('rank.in') as f:
	with open('rank.out', 'w') as o:
		t = int(f.readline())
		for i in range(t):
			counts = {}
			n = int(f.readline())
			for j in range(2*n-1):
				row = [int(x) for x in f.readline().strip().split(' ')]
				for x in row:
					counts[x] = counts.get(x, 0) + 1
			wut = []
			for key, val in counts.iteritems():
				if val % 2 == 1:
					wut.append(key)
			wut = sorted(wut)
			o.write('Case #{}: {}\n'.format(i+1, ' '.join(str(x) for x in wut)))