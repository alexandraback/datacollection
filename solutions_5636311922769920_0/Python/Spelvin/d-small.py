'''
If K = S, you can just check the first K tiles. Those tiles are either a full copy
of the original sequence, which will clearly tell you whether that sequence contained
any gold, or all gold, in which case the original sequence will contain some
gold.
'''

def gradstringmaker(s):
	outputstring = ''
	for i in range(1,s+1):
		outputstring += ' '
		outputstring += str(i)
	return outputstring[1:]

import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		s = int(inputLines.pop(0).rstrip().split()[2])
		fileOUT.write('Case #' + str(num+1) + ': ' + gradstringmaker(s) + '\n')