#!/usr/bin/python

import math
import subprocess

def factors(M):
	p = subprocess.Popen("factor " + str(M), shell=True, stdout=subprocess.PIPE)
	return [int(x) for x in p.stdout.readline().split(':')[1].split()]

T = input()
for t in range(1, T + 1):
	B, M = [int(x) for x in raw_input().split()]

	F = factors(M)
	if sum(F) + 1 > B:
		print "Case #%d: %s" % (t, 'IMPOSSIBLE')
	else:
		print "Case #%d: %s" % (t, 'POSSIBLE')

		matrix = [['0'] * B for b in range(B)]

		if M == 1:
			matrix[0][B-1] = '1'
		else:	
			for i in range(1, F[0]):
				matrix[0][i] = '1'
			indices = range(F[0])
			
			maxIndex = F[0]
			rowIndex = 1
			for f in F[1:]:
				newIncides = range(maxIndex, maxIndex + f)

				for index in indices:
					for newIndex in newIncides:
						matrix[index][newIndex] = '1'

				indices = newIncides
				maxIndex += f
				rowIndex += 1

			for index in indices:
				matrix[index][B - 1] = '1'

		for row in matrix:
			print ''.join(row)
