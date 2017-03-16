
def solve(arminsize, othermotes):
	othermotes = sorted(othermotes)
	
	# (arminsize, index in othermotes) => min number of operations
	dptable = {}
	
	def solvedp(asize, index):
		
		if (asize, index) not in dptable:
			# dynamic programming: either add a mote of maximum size (arminsize-1)
			# for armin to absorb or remove a mote by incrementing the index
			
			if index >= len(othermotes):
				# all motes consumed
				dptable[(asize, index)] = 0
			elif asize > othermotes[index]:
				# can consume smallest mote
				dptable[(asize, index)] = solvedp(asize + othermotes[index], index + 1)
			elif asize == 1:
				# have to remove, armin cannot consume a smaller mote
				dptable[(asize, index)] = 1 + solvedp(asize, index + 1)
			else:
				# either remove a mote or add a mote one smaller than asize.
				# both costs one operation
				dptable[(asize, index)] = 1 + min(
					solvedp(asize, index + 1),
					solvedp(asize + (asize - 1), index),
				)

		return dptable[(asize, index)]
	
	result = solvedp(arminsize, 0)
	#print dptable
	return result

# MAIN

import sys

input = open(sys.argv[1]).readlines()

numtestcases = int(input[0])

for tc in range(0, numtestcases):
	arminsize, nummotes = map(int, input[2 * tc + 1].split(" "))
	othermotes = map(int, input[2 * tc + 2].split(" "))
	
	print "Case #" + str(tc + 1) + ": " + str(solve(arminsize, othermotes))