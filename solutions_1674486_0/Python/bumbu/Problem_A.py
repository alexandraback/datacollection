import copy
import string
from decimal import *
getcontext().prec = 6

_file = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1C/Problem_A/A-small-attempt1.in")
lines = int(_file.readline())
_result = open("D:/Dropbox/Projects/CodeJAM/2012 Round 1C/Problem_A/result.txt", "w")

def numbersOfPaths(relations, i, j):
	#print i, j, amount
	amount = 0
	for x in relations[i]:
		#print x, j
		if int(x) == j:
			amount += 1
		else:
			amount += numbersOfPaths(relations, int(x), j)
	return amount

line = _file.readline()
i = 1
while(line != ""):
	line = line.replace("\n", "")

	numbers = int(line)

	relations = {}
	for j in range(1,numbers+1):
		line = _file.readline().replace("\n", "")
		relations[j] = line.split(" ")[1:]
		#print points

	result = False
	# check for all possible ways
	for x in range(1, numbers+1):
		for y in range(1, numbers+1):
			if x != y:
				paths_nr = numbersOfPaths(relations, x, y)
				#print paths_nr
				if paths_nr > 1:
					result = True
					break
		if result:
			break

	if result:
		result = "Yes"
	else:
		result = "No"
	
	#print relations	

	

	if i > 1:
		_result.write("\n")
	_result.write("Case #" + str(i) + ": " + result)
	line = _file.readline()
	i += 1
	

_file.close()
_result.close()