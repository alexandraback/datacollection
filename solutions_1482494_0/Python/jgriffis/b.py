
fin = open("B-small-attempt1.in", 'r')
fout = open("b.out", 'w')

cases = int(fin.readline().strip())

for i in range(cases):
	num_levels = int(fin.readline().strip())
	
	levels = []
	completed = []
	for j in range(num_levels):
		levels.append([int(n) for n in fin.readline().strip().split(' ')])
		levels[j].insert(0, j)
		completed.append(0)

	steps = 0
	stars = 0
	done = 0

	result = ""
	while done < num_levels:
		steps += 1

		candidates = [l[0] for l in levels if completed[l[0]] == 0 and l[2] <= stars]	# Fresh 2's
		if len(candidates) > 0:
			completed[candidates[0]] = 2
			stars += 2
			done += 1
			continue
			
		candidates = [l[0] for l in levels if completed[l[0]] == 1 and l[2] <= stars]	# Bump 2's
		if len(candidates) > 0:
			completed[candidates[0]] = 2
			stars += 1
			done += 1
			continue

		candidates = [l for l in levels if completed[l[0]] == 0 and l[1] <= stars]	# Fresh 1's
		if len(candidates) > 0:
			candidates = sorted(candidates, key=lambda level: level[2], reverse=True)
			candidates = [c[0] for c in candidates]
			completed[candidates[0]] = 1
			stars += 1
			continue
		
		result = "Too Bad"
		break

	if result == "":
		result = str(steps)
		
	fout.write('Case #%d: %s\n' % (i + 1, result))
