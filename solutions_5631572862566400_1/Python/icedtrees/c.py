from collections import Counter

t = int(raw_input())
for c in range(1,t+1):
	n = int(raw_input())
	kids = map(int, raw_input().split())
	kids = [k-1 for k in kids]
	cycles = []
	cycle_nums = set()
	for i in range(n):
		if i in cycle_nums: continue
		j = i
		k = 0
		while k == 0 or j != i:
			if k == n + 1: break
			k += 1
			j = kids[j]
		if k != n + 1:
			cycle = [i]
			for l in range(k-1):
				cycle.append(kids[cycle[-1]])
			for m in cycle:
				cycle_nums.add(m)
			cycles.append(cycle)

	cycles2 = [cycle for cycle in cycles if len(cycle) == 2]
	cycle_nums_2 = {o for i,p in enumerate(cycles2) for o in p}
	cyclesA = [cycle for cycle in cycles if len(cycle) > 2]

	best2 = {i:0 for i in cycle_nums_2}

	for i in range(n):
		if i in cycle_nums: continue
		j = i
		k = 0
		while k == 0 or j != i:
			if j in cycle_nums: break
			k += 1
			j = kids[j]
		if j in cycle_nums_2:
			best2[j] = max(best2[j], k)

	bestbest2 = sum(best2.values()) + len(cycle_nums_2)
	bestA = max(len(cycle) for cycle in cycles)
	result = max(bestbest2, bestA)
	
	print "Case #{}: {}".format(c, result)

