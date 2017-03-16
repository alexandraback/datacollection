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
		R = int(currentCase[0])
		C = int(currentCase[1])
		W = int(currentCase[2])
		
		wastedPoints = R* (C//W) -1
		extra_turn = 0 if C%W==0 else 1
		writeOutput (nCase, wastedPoints + extra_turn + W)
		
def clearfile ():
	with open (OUTPATH, 'w') as file:
			file.write("")
		
def writeOutput (nCase, answer):
	with open (OUTPATH, 'a') as file:
		file.write ("Case #%i: %i\n" % (nCase, answer) )
		
if __name__ == "__main__":
	nCases, data =loadCases("A-small-attempt0.in")
	getNumFriends (nCases, data)