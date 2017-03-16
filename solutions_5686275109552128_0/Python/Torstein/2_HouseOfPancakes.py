# Google Codejam 2015 Qualifier
# Infinite House of Pancakes


def getMaxPancakes(roof, pancakeCount):
	while roof > 0 and pancakeCount[roof] == 0:
		roof -= 1
	return roof
	

testcases = int(raw_input().strip())
for testcase in xrange(testcases):
	dinerCount = int(raw_input())
	diners = map(int, raw_input().split())
	
	maxPancakes = max(diners)
	absMax = maxPancakes
	pancakeCount = [0] * (1+maxPancakes)
##	for diner in diners:
##		pancakeCount[diner] += 1

	bestTime = maxPancakes

	for topPile in xrange(1,absMax+1):
		divisions = 0
		for guy in diners:
			divisions += (guy-1)/topPile
		bestTime = min(bestTime, topPile+divisions)

	##while maxPancakes > 1:
	##	# Divide all maximum tiles into two
	##	divisions += pancakeCount[maxPancakes]
	##	smallhalf = maxPancakes / 2
	##	bighalf = maxPancakes - smallhalf
	##	pancakeCount[smallhalf] += pancakeCount[maxPancakes]
	##	pancakeCount[bighalf] += pancakeCount[maxPancakes]
	##	pancakeCount[maxPancakes] = 0
	##	maxPancakes = getMaxPancakes(maxPancakes, pancakeCount)
	#	bestTime = min(bestTime, maxPancakes+divisions)

	print "Case #%d:" % (testcase+1), bestTime
