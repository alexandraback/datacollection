#!/usr/bin/python3
import sys, os

file_prefix = 'B-' + ['sample', 'small-attempt0', 'large'][2]
filein = open(file_prefix + '.in', 'r')
fileout = sys.stdout if 'sample' in file_prefix else open(file_prefix + '.out', 'w')
linein = lambda: filein.readline().strip()
lineout = lambda s, *args: fileout.write(s.format(*args) + '\n')

ncases = int(linein())

for case in range(ncases):
	B, M = (int(x) for x in linein().split())

	# binary decomposition
	binaryM = "{0:b}".format(M).zfill(B - 1)

	maxPaths = 2 ** (B - 2)

	output = []

	print("M:", M, "(" + str(binaryM) + ")", "maxPaths:", maxPaths)

	if maxPaths < M:
		possible = False
	else:
		possible = True
		for i in range(B):
			line = ''
			for j in range(B-1):
				line += '1' if j > i else '0'

			if i == B - 1:
				line += '0'
			elif M == maxPaths:
				line += '1'
			else:
				line += ('0' if i == 0 else binaryM[-i])
			output.append(line)

	lineout("Case #{0}: {1}", case + 1, 'POSSIBLE' if possible else 'IMPOSSIBLE')
	for line in output:
		lineout(line)
