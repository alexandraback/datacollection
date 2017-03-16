
def sheepcount(n):
	count = 0
	number = 0
	digits = ['0','1','2','3','4','5','6','7','8','9']
	for k in range(1000001):
		number += n
		for char in str(number):
			if char in digits:
				digits.remove(char)
		if digits == []:
			return str(number)
	return 'INSOMNIA'

import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		n = int(inputLines.pop(0))
		fileOUT.write('Case #' + str(num+1) + ': ' + sheepcount(n) + '\n')
