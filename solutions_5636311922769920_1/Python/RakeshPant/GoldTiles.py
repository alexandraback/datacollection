import itertools
import math

def checkIfGoldIsThere(integerVal):
	return 1 # dummy for future
		
outputList = []

#get the data 
with open ('C:/Users/rpant/Desktop/Python_Programs/GoldTiles/input.txt') as data :
	totalNumberOfCases = data.readline()
	for i in range (int(totalNumberOfCases)):
		testCaseStr = data.readline().strip()
		(strK, strC, strS) = testCaseStr.split(' ')
		if int(strS) <= int(strK)/2 :
			outputList.append("IMPOSSIBLE")
			continue
			
		#get final length of the string
		finalLength = math.pow(int(strK), int(strC))
		nbrOfCombos = math.floor(finalLength/int(strK))
		#get the middle bit pattern
		mid = math.floor(nbrOfCombos/2)
		left = mid*int(strK)+1
		
		if left <= 0:
			left=1
			
		right = left + int(strS)-1
		
		if left == right:
			outputList.append(str(left))
		else:
			tempStr = str(left)
			for i in range (1, int(strS)):
				tempStr=tempStr + ' ' + str(left+i) 
			outputList.append(tempStr)
			
#create output file
with open ('C:/Users/rpant/Desktop/Python_Programs/GoldTiles/output.txt', "w") as os :	
	for index in range(len(outputList)):
		print('Case #' + str(index+1) + ': ' + str(outputList[index]), file=os)