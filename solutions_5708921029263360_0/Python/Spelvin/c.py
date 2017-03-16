def outfitlistmaker(j,p,s):
	output = []
	for x in range(1,j+1):
		for y in range(1,p+1):
			for z in range(1,s+1):
				output.append([x,y,z])
	return output
	
def countmatrix(c,d):
	outputx = []
	for x in range(c):
		outputy = []
		for y in range(d):
			outputy.append(0)
		outputx.append(outputy)
	return outputx
	
def greedyoutfitplanner(j,p,s,k):
	outfitlist = outfitlistmaker(j,p,s)
	outfitsworn = []
	violationmatrix01 = countmatrix(j,p)
	violationmatrix02 = countmatrix(j,s)
	violationmatrix12 = countmatrix(p,s)
	for potentialoutfit in outfitlist:
		piece0 = potentialoutfit[0]-1
		piece1 = potentialoutfit[1]-1
		piece2 = potentialoutfit[2]-1
		if violationmatrix01[piece0][piece1] < k and violationmatrix02[piece0][piece2] < k and violationmatrix12[piece1][piece2] < k:
			violationmatrix01[piece0][piece1] += 1
			violationmatrix02[piece0][piece2] += 1
			violationmatrix12[piece1][piece2] += 1
			outfitsworn.append(potentialoutfit)
	return outfitsworn

import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		quartet = inputLines.pop(0).rstrip().split(' ')
		j = int(quartet[0])
		p = int(quartet[1])
		s = int(quartet[2])
		k = int(quartet[3])
		outfitsworn = greedyoutfitplanner(j,p,s,k)
		fileOUT.write('Case #' + str(num+1) + ': ' + str(len(outfitsworn)) + '\n')
		for outfit in outfitsworn:
			fileOUT.write(' '.join([str(x) for x in outfit]) + '\n')
