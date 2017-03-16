fin = open("C-small-2-attempt0.in", 'r')
fout = open("out.txt", 'w')

def getFirstTime(cycle, position):
	return float(360 - position) * cycle / 360

def getCycleTime(cycle, position, x):
	if x < getFirstTime(cycle, position):
		return 1
	else:
		return int((x - getFirstTime(cycle, position))/cycle)

def getCount(hikers, x):
	s = 0
	for hiker in hikers:
		c, p = hiker
		s += getCycleTime(c, p, x)
	return s

def intersects(cycle1, position1, cycle2, position2):
	f1 = getFirstTime(cycle1, position1)
	f2 = getFirstTime(cycle2, position2)
	return (f1 < f2 and f2 < f1 + cycle1) or (f2 < f1 and f1 < f2 + cycle2)

cases = int(fin.readline())
for case in range(cases):
	n = int(fin.readline())
	hikers = []
	for i in range(n):
		(d, h, m) = map(int, str.split(fin.readline()))
		for j in range(h):
			hikers.append((m + j, d))

	if len(hikers) < 2:
		result = 0
	else:
		counts = []
		for h in hikers:
			c, p = h
			counts.append(sum([getCycleTime(cy, po, getFirstTime(c, p)) for (cy, po) in hikers]))
		result = min(counts)
	fout.write("Case #" + str(case + 1) + ": " + str(result) + "\n")

fin.close()
fout.close()