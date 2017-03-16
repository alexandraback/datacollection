import math

def iteratebinarylist(lst):
	if lst[-1] == 0:
		return lst[:-1] + [1]
	else:
		return iteratebinarylist(lst[:-1]) + [0]

def jamcoinmaker(lst):
	halflist = [1] + lst + [1]
	fulllist = halflist + halflist
	outputstring = ''
	for num in fulllist:
		outputstring += str(num)
	for num in divisorlist:
		outputstring += ' '
		outputstring += str(num)
	return outputstring

divisorlist = [k**16+1 for k in range(2,11)]
binarylist = [0 for k in range(14)]

import sys
		
with open(sys.argv[1], "w") as fileOUT:
	fileOUT.write('Case #1:' + '\n')	
	for i in range(500):
		binarylist = iteratebinarylist(binarylist)
		fileOUT.write(jamcoinmaker(binarylist) + '\n')
