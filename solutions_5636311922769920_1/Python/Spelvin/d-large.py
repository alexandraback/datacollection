def liststoencode(k,c):
	output = []
	if k % c == 0:
		numberoflists = k // c
	else:
		numberoflists = (k // c) + 1
	counter = 0
	for i in range(numberoflists):
		newlist = []
		for j in range(c):
			if counter == k:
				newlist.append(0)
			else:
				newlist.append(counter)
				counter += 1
		output.append(newlist)
	return output

def listtomodk(lst,k):
	output = 0
	for num in lst:
		output *= k
		output += num
	return output

def tilestocheck(k,c):
	lsts = liststoencode(k,c)
	nums = [listtomodk(lst,k)+1 for lst in lsts]
	output = ''
	for num in nums:
		output += ' '
		output += str(num)
	return output[1:]
	

import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		inputlist = inputLines.pop(0).rstrip().split()
		k = int(inputlist[0])
		c = int(inputlist[1])
		s = int(inputlist[2])
		if s*c < k:
			fileOUT.write('Case #' + str(num+1) + ': ' + 'IMPOSSIBLE' + '\n')
		else:
			fileOUT.write('Case #' + str(num+1) + ': ' + tilestocheck(k,c) + '\n')