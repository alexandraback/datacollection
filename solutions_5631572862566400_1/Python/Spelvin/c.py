def bff(lst,kid):
	return lst[kid-1]
	
def orbit(lst,kid):
	chain = [kid]
	while True:
		chain.append(bff(lst,chain[-1]))
		if len(chain) > 2 and chain[-1] == chain[-3]:
			return [chain[:-1],'chain']
		if len(chain) > 3 and chain[-1] in chain[:-2]:
			return [chain[chain.index(chain[-1]):-1],'circle']

def listreverse(lst):
	if len(lst) == 1:
		return lst
	return listreverse(lst[1:]) + [lst[0]]

def biggestcircle(lst):
	circles = []
	chains = []
	for kid in range(1,len(lst)+1):
		potential = orbit(lst,kid)
		if potential[1] == 'circle':
			circles.append(potential[0])
		else:
			chains.append(potential[0])
	if circles == []:
		bestcircle = 0
	else:
		bestcircle = max([len(x) for x in circles])
	return max(bestcircle,newbestchaincombo(chains,len(lst)))
	
def bestchaincombo(listofchains,elementsused):
	if listofchains == []:
		return len(elementsused)
	if len([x for x in listofchains[0] if x in elementsused]) == 0:
		return max(bestchaincombo(listofchains[1:],elementsused+listofchains[0]),bestchaincombo(listofchains[1:],elementsused))
	return bestchaincombo(listofchains[1:],elementsused)
	
def chainimprover(listofchains):
	newchains = []
	for chain1 in listofchains:
		for chain2 in listofchains:
			if len(chain1) > 2 and len(chain2) > 2 and chain1[-1] == chain2[-2] and chain1[-2] == chain2[-1]:
				newchains.append(chain1[:-2] + listreverse(chain2))
	return listofchains + newchains

def newbestchaincombo(listofchains,numberofkids):
	bestchainsizes = []
	for kid in range(1,numberofkids+1):
		chainsendinginkid = [x for x in listofchains if x[-1] == kid]
		if chainsendinginkid != []:
			bestchainsizes.append(max([len(x) for x in chainsendinginkid]))
	return sum(bestchainsizes) - len(bestchainsizes)
	
	
import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		inputLines.pop(0)
		bfflist = [int(x) for x in inputLines.pop(0).rstrip().split()]
		fileOUT.write('Case #' + str(num+1) + ': ' + str(biggestcircle(bfflist)) + '\n')