OUTPATH = "out.txt"
def loadCases (filePath):
	data = []
	nCases = 0
	with open (filePath, 'r') as file:
		fileData = file.read()
		data = fileData.split("\n")
		nCases = data.pop(0)
		data.pop()
	return (nCases, data)
	
def getNumFriends (nCases, data):
	nCase = 0
	clearfile()
	while data:
		nCase += 1
		currentCase = data.pop(0)
		currentCase = currentCase.split(" ")
		C = int(currentCase[0])
		D = int(currentCase[1])
		V = int(currentCase[2])
		denominations = getList (data.pop(0))
		
		newDen = denominations
		
		addDen = 0
		
		allPos = {x+y for x in newDen for y in newDen if x!=y}
		for d in newDen:
			allPos.add(d)
			
		for i in range (V):
			if (i+1) not in allPos:
				addDen += 1
				newDen.append(i+1)
				allPos = {x+y for x in newDen for y in newDen if x!=y}
				for d in newDen:
					allPos.add(d)
		
		writeOutput(nCase, addDen)			
		
def clearfile ():
	with open (OUTPATH, 'w') as file:
			file.write("")
		
def writeOutput (nCase, answer):
	with open (OUTPATH, 'a') as file:
		file.write ("Case #%i: %i\n" % (nCase, answer) )
		
def getList (numbers):
	list = []
	for i in numbers.split(" "):
		list.append(int(i))
	return list
		
if __name__ == "__main__":
	#nCases, data =loadCases("in.in")
	nCases, data =loadCases("C-small-attempt0.in")
	#nCases, data =loadCases("A-large.in")
	getNumFriends (nCases, data)