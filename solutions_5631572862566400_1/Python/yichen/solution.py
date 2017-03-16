def solve(case_number):
	size = int(raw_input())
	bff = [0] + [int(s) for s in raw_input().split(" ")]
	not_considered = [i for i in range(1,size + 1)]
	largest_cycle = 0
	pairs = {}
	while not_considered:
		path = [not_considered[0]]
		not_considered.remove(not_considered[0])
		not_completed = True
		while not_completed:
			next = bff[path[-1]]
			if next in not_considered:
				not_considered.remove(next)
			if next in path:
				not_completed = False
				if next == path[-2]:
					new_pair = tuple(sorted([next, path[-1]]))
					if new_pair in pairs:
						pairs[new_pair] += [path]
					else:
						pairs[new_pair] = [path]
				else:
					length_of_cycle = len(path) - path.index(next)
					if length_of_cycle > largest_cycle:
						largest_cycle = length_of_cycle
			else:
				path.append(next)
	pair_length = 0
	for key, paths in pairs.items():
		paths.sort(key=lambda p: -len(p))
		lp = paths[0]
		lp_last = lp[-1]
		total = len(lp)
		for p in paths:
			if p[-1] != lp_last:
				total += len(p) - 2
				break
		pair_length += total
	print "Case #{}: {}".format(case_number, max(largest_cycle, pair_length))

t = int(raw_input())  # read a line with a single integer
for case in xrange(1, t + 1):
	solve(case)
'''
python solution.py <small.in> small.out
python solution.py <large.in> large.out
'''