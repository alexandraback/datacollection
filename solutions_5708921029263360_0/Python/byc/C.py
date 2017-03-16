#!/usr/bin/python3
import sys, os

file_prefix = 'C-' + ['sample', 'small-attempt0', 'large'][1]
filein = open(file_prefix + '.in', 'r')
fileout = sys.stdout if 'sample' in file_prefix else open(file_prefix + '.out', 'w')
linein = lambda: filein.readline().strip()
lineout = lambda s, *args: fileout.write(s.format(*args) + '\n')

ncases = int(linein())

for case in range(ncases):
	A, B, C, K = (int(x) for x in linein().split())

	parts = [A, B, C]
	arrangements = [
		(0, 1, 2),
		(1, 0, 2),
		(2, 0, 1),
	]

	bestOutput = None
	bestNum = None

	for oId, aId, bId in arrangements:
		oVal = parts[oId]
		aVal = parts[aId]
		bVal = parts[bId]

		amount = min(oVal, K) * aVal * bVal

		output = []
		for i in range(min(oVal, K)):
			for j in range(aVal):
				for k in range(bVal):
					line = [None, None, None]
					line[oId] = str(i + 1)
					line[aId] = str(j + 1)
					line[bId] = str(k + 1)
					output.append(' '.join(line))

		if bestNum is None or amount < bestNum:
			bestNum = amount
			bestOutput = output

	lineout("Case #{0}: {1}", case + 1, bestNum)
	for line in bestOutput:
		lineout(line)
