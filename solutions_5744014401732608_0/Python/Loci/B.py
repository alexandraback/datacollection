
cases = int(raw_input())

debug = False

for case in range(cases):

	buildings,ways = [int(i) for i in raw_input().split()]
	#if debug:
	#print buildings, ways


	oldways = ways

	slideDict = {}
	for building in range(1,buildings+1):
		slideDict[building] = [0]*buildings


	for building in range(1,buildings+1):
		newSlides = buildings-building
		if debug:
			print "Node " + str(building) + " can build " + str(newSlides) + " slides"

		if ways < newSlides:
			slidesNeeded = ways
			#ways = 0
		else:
			slidesNeeded = newSlides
			#ways -= newSlides

		if debug:
			print "Node " + str(building) + " will build " + str(slidesNeeded) + " slides"


		#ways -= slidesNeeded


		for slideNeeded in reversed(range(building+1,buildings+1)):
			if slidesNeeded  <= 0:
				break

			if slideDict[building][slideNeeded-1] == 1:
				continue

			slidesNeeded -= 1

			if debug:
				print ways

			slideDict[building][slideNeeded-1] = 1
			slideDict[slideNeeded][buildings-1]=1
			ways -= 1

			
		#print slideDict

		
	if ways > 0:
		print "Case #" + str(case+1) + ": IMPOSSIBLE"
		continue

	answer = []
	slideDict[buildings] = [0]*buildings

	print "Case #" + str(case+1) + ": POSSIBLE"
	for slidePlan in slideDict:
		print ''.join([str(i) for i in slideDict[slidePlan]])

	if debug:
		print

