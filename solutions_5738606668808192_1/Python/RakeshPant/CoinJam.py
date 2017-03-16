import itertools
import math

def getNonPrimeDivisor(integerVal):
	n = integerVal
	if n % 2 == 0 and n > 2: 
		return(2)
	for i in range(3, int(math.sqrt(n)) + 1, 2):
		if n % i == 0:
			return(i)
		if i > 10000 :
		    break
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
if int(strLen) > 16:
	strLen1 = 15
	strLen2 = int(strLen)-(17)
tempList1 = list(["".join(seq) for seq in itertools.product("01", repeat=int(strLen1))])
tempList2 = list(["".join(seq) for seq in itertools.product("01", repeat=int(strLen2))])
tempList1 = ['1' + tempList1 for tempList1 in tempList1]
tempList2 = [s + '1' for s in tempList2]
 
outputList.append('Case #1:')

for i in range (len(tempList1)):
	for j in range (len(tempList2)):
		tempString = tempList1[i] + tempList2[j]
		print(tempString)
		outPtString = str(tempString)
		integerVal = int(tempString, 2)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)

		integerVal = int(tempString, 3)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)
		
		integerVal = int(tempString, 4)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)

		integerVal = int(tempString, 5)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)

		integerVal = int(tempString, 6)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)

		integerVal = int(tempString, 7)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)

		integerVal = int(tempString, 8)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)

		integerVal = int(tempString, 9)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)

		integerVal = int(tempString, 10)
		print(integerVal)
		divisor = getNonPrimeDivisor(integerVal)
		if divisor == -1:
			continue
		outPtString = outPtString + " " + str(divisor)
		outputList.append(outPtString)
		print(outPtString)
		if len(outputList) == int(nuberOfCombReqd)+1:
			with open ('C:/Users/rpant/Desktop/Python_Programs/CoinJam/output.txt', "w") as os :	
				for index in range(len(outputList)):	
					print(str(outputList[index]), file=os)
			break
	break