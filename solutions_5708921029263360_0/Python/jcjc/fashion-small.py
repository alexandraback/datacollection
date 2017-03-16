import sys

filename = sys.argv[1]
f = open(filename, 'r')

numCases = int(f.readline())

for t in range(numCases):
	J, P, S, K = map(int, f.readline().split())
	combination = []
	jp_counts = {}
	js_counts = {}
	ps_counts = {}
	for s in range(1, S+1):
		for p in range(1, P+1):
			for j in range(1, J+1):
				jp_count = jp_counts.get((j,p), 0)
				js_count = js_counts.get((j,s), 0)
				ps_count = ps_counts.get((p,s), 0)
				if jp_count == K or js_count == K or ps_count == K:
					pass
				else:
					combination.append((j,p,s))
					jp_counts[(j,p)] = jp_count + 1
					js_counts[(j,s)] = js_count + 1
					ps_counts[(p,s)] = ps_count + 1		

	output = 'Case #{}: {}\n'.format(t+1, len(combination))
	for comb in combination:
		output = output + ' '.join(map(str, comb)) + '\n'
	print output.strip()