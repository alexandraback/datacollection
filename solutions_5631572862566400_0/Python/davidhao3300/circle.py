with open('circle.in') as f:
	with open('circle.out', 'w') as o:
		t = int(f.readline())
		for i in range(t):
			n = int(f.readline())
			arr = [0]
			row = [0] + [int(x) for x in f.readline().strip().split(' ')]
			group = 1
			groups = [0]*(n+1)
			max_length = 0
			rows = []
			have_two = False
			can_joins = []
			in_play = range(1, n+1)
			results = {}
			for j in range(1, n+1):
				if groups[j] == 0:
					a_row = []
					while groups[j] == 0:
						groups[j] = group
						a_row.append(j)
						j = row[j]
					if j == a_row[0]:
						#print 'cycle', a_row
						max_length = max(max_length, len(a_row))
						for x in a_row:
							in_play.remove(x)
					else:
						results[a_row[0]] = len(a_row)
						results[a_row[-1]] = len(a_row)
						#print 'open', a_row
						for x in a_row[1:-1]:
							in_play.remove(x)
				group += 1
			for key in results.keys():
				max_length = max(max_length, results[key] + results.get(row[key], 0))
			o.write('Case #{}: {}\n'.format(i+1, max_length))