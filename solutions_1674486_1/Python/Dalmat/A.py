#!/usr/bin/env python

import sys, os.path, re, copy
import itertools, operator


def computeResult2(classnb, input):

	container = [set()]*(classnb+1)
	oldcontainer = set()	
	
	#print "%s %s" % (classnb, input)	
	
	for i in range(1,classnb+1):		
		container[i] = set(input[i-1][1:])
		
	while oldcontainer != container:
		#print "%s" % container
		oldcontainer = copy.deepcopy(container)
		for i in range(1,classnb+1):
			
			tempcontainer = copy.deepcopy(container[i])

			for j in tempcontainer:
				if j != i and len(container[j])>0:
					if len(container[i] & container[j]) > 0:
							return "Yes"
					container[i].discard(j)
					container[i] = container[i].union(container[j])					
			

	return "No"


def computeResult3(classnb, input):

	container = [set()]*(classnb+1)
	oldcontainer = set()	
	
	#print "%s %s" % (classnb, input)	
	
	for i in range(1,classnb+1):
		container[i] = set(input[i-1][1:])
		
	while oldcontainer != container:
		#print "%s" % container
		oldcontainer = copy.copy(container)
		for i in range(1,classnb+1):
			
			tempcontainer = copy.copy(container[i])

			for j in tempcontainer:
				if len(container[j])>0:
					if len(container[i] & container[j]) > 0:
							return "Yes"
					container[i].discard(j)
					container[i] = container[i].union(container[j])
			

	return "No"



if __name__ == '__main__':

	if len(sys.argv) != 2 or not os.path.isfile(sys.argv[1]):
		inputFile = sys.stdin
	else:
		inputFile = open(sys.argv[1], 'r')

	testNB = 0
	inputFile.readline()
	
	while True:
		
		line = inputFile.readline()
		if line == "":
			break 

		testNB += 1


		classnb = int(line.strip())
		input = []
		for i in range(classnb):
			input.append([ int(x) for x in inputFile.readline().split() ])		

		result = computeResult3(classnb, input)
		print("Case #%s: %s" % (testNB, result))		

exit(0)
