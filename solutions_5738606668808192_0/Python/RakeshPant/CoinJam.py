import itertools
import math

def getNonPrimeDivisor(integerVal):
	n = integerVal
	if n % 2 == 0 and n > 2: 
		return(2)
	for i in range(3, int(math.sqrt(n)) + 1, 2):
		if n % i == 0:
			return(i)
	return(-1)
		
outputList = []
primeNumberList = set()
strLen = 1
nuberOfCombReqd = 1

#get the data 
with open ('C:/Users/rpant/Desktop/Python_Programs/CoinJam/input.txt') as data :
	totalNumberOfCases = data.readline()
	testCaseStr = data.readline().strip()
	(strLen, nuberOfCombReqd) = testCaseStr.split(' ')
	
#get all combinations of n
tempList = list(["".join(seq) for seq in itertools.product("01", repeat=int(strLen)-2)])
tempList = ['1' + tempList for tempList in tempList]
tempList = [s + '1' for s in tempList]
tempList.sort() 
outputList.append('Case #1:')

for index in range (len(tempList)):
	outPtString = str(tempList[index])
	integerVal = int(tempList[index], 2)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)

	integerVal = int(tempList[index], 3)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)
	
	integerVal = int(tempList[index], 4)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)

	integerVal = int(tempList[index], 5)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)

	integerVal = int(tempList[index], 6)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)

	integerVal = int(tempList[index], 7)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)

	integerVal = int(tempList[index], 8)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)

	integerVal = int(tempList[index], 9)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)

	integerVal = int(tempList[index], 10)
	divisor = getNonPrimeDivisor(integerVal)
	if divisor == -1:
		continue
	outPtString = outPtString + " " + str(divisor)
	
	outputList.append(outPtString)
	if len(outputList) == int(nuberOfCombReqd)+1:
		break
	
with open ('C:/Users/rpant/Desktop/Python_Programs/CoinJam/output.txt', "w") as os :	
	for index in range(len(outputList)):	
		print(str(outputList[index]), file=os)