def numberlength(num):
	return len(str(num))

def reversenumber(num):
	return int(str(num)[::-1])
	
def stepstolength(n):
	if n == 1:
		return 1
	if n == 2:
		return 10
	if n % 2 == 1:
		k = n // 2
		return stepstolength(n-1) + 10**k + 10**k - 1
	else:
		k = n // 2
		return stepstolength(n-1) + 10**k + 10**(k-1) - 1

def stepsfrompoweroften(num):
	numberasstring = str(num)
	numlength = len(numberasstring)
	candidates = []
	if num == 10**(numlength-1):
		return 0
	if num % 10 == 0:
		return 1 + stepsfrompoweroften(num - 1)
	for i in range(1,numlength):
		leftside = numberasstring[:i][::-1]
		rightside = numberasstring[i:]
		candidates.append(int(leftside)+int(rightside))
	candidates.append(num - 10**(numlength-1))
	return min(candidates)
	
def stepstonumber(num):
	if num < 20:
		return num
	numlength = len(str(num))
	return stepstolength(numlength) + stepsfrompoweroften(num)

import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		inputnum = int(inputLines.pop(0))
		fileOUT.write('Case #' + str(num+1) + ': ' + str(stepstonumber(inputnum)) + '\n')