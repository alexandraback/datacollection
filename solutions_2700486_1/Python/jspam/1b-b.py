import sys
sys.setrecursionlimit(10000)

def solve(numdiamonds, targetx, targety):

	dptable = {}

	def solveprob(left, right, total, height, maxheight):
		if (left, right, total, height, maxheight) not in dptable:
		#print "solveprob", left, right, "total", total, "target", height, "maxheight", maxheight
	
			if total <= 0:
				#print
				dptable[(left, right, total, height, maxheight)] = (left >= height)
			elif left >= height:
				#print "= 1.0"
				dptable[(left, right, total, height, maxheight)] = 1.0
			elif right == maxheight:
				#print "= " + str(float(left + total >= height))
				dptable[(left, right, total, height, maxheight)] = (left + total >= height)
			else:
				#print
				dptable[(left, right, total, height, maxheight)] = 0.5 * solveprob(left + 1, right, total - 1, height, maxheight) + \
				0.5 * solveprob(left, right + 1, total - 1, height, maxheight)
		
		return dptable[(left, right, total, height, maxheight)]

	# one "shower" of diamonds is a sequence of falling diamonds that form a triangle.
	
	# find out for how many showers the diamonds last
	temp = numdiamonds
	totalshowers = 0
	remaining = numdiamonds
	
	while temp > 0:
		temp -= 4 * totalshowers + 1
		totalshowers += 1
		
		if temp > 0:
			remaining = temp
	
	# find out the number of the shower our target lies in.
	targetshower = ((abs(targetx) + targety) // 2) + 1
	
	if targetshower > totalshowers:
		return 0.0
	elif targetshower < totalshowers:
		return 1.0
	else:
		#print "numdiamonds", numdiamonds, "totalshowers", totalshowers, "targetxy", targetx, targety, "targetshower", targetshower, "remaining", remaining
	
		if remaining == 4 * (targetshower-1) + 1:
			return 1.0
		elif targetx == 0:
			return 0 # top will never be reached by a partly shower
		else:
			# magic happens
			return solveprob(0, 0, remaining, targety + 1, abs(targetx) + targety)


# MAIN

import sys

input = open(sys.argv[1]).readlines()

numtestcases = int(input[0])

for tc in range(0, numtestcases):
	numdiamonds, targetx, targety = map(int, input[tc + 1].split(" "))
	print "Case #" + str(tc + 1) + ": " + str(solve(numdiamonds, targetx, targety))