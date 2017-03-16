import sys, math

def map(func, l):
	return [func(i) for i in l]

def parseCase(instrm):
	instrm.readline()
	naomi = map(float, instrm.readline().strip().split(" "))
	ken = map(float, instrm.readline().strip().split(" "))
	return (naomi, ken)

def solveCase(input):
	(naomi, ken) = input
	allblocks = []
	for block in naomi:
		allblocks.append((block, +1))
	for block in ken:
		allblocks.append((block, -1))
	
	allblocks.sort(key=lambda block:-block[0])
	
	warScore = 0
	cumsum = 0
	for block in allblocks:
		cumsum += block[1]
		if (cumsum > warScore):
			warScore = cumsum
	
	dwarScore = 0
	naomi.sort()#increasing
	ken.sort()#increasing
	i = 0
	for j in range(len(ken)):
		while (i < len(naomi) and naomi[i] < ken[j]):
			i += 1
		if (i == len(naomi)):
			break
		dwarScore += 1
		i += 1
	
	return str(dwarScore) + " " + str(warScore)


if __name__=="__main__":
	instrm = open(sys.argv[1])
	cases = int(instrm.readline().strip())
	for c in range(cases):
		input = parseCase(instrm)
		res = str(solveCase(input))
		print("Case #" + str(c+1) +": "+res)
	instrm.close()