#!/usr/bin/python
# -*- coding: utf-8 -*-

def line2floatlist(line):
    list = line.split(' ')
    numbers = [ float(x) for x in list ]
    return numbers

def prob(A, B, probabilities):
	probGotIt = 1
	typesMin = 10000000
	for i in xrange(0, A + 1):
		probKorrect = 1.0
		for el in probabilities[0:(len(probabilities)-i)]:
			probKorrect *= el
		probWrong = 1.0 - probKorrect
		remainingTypes = i + (B - A + i) + 1
		remainingTypesErr = remainingTypes + B + 1
		types = probKorrect*remainingTypes + probWrong*remainingTypesErr
		#print types
		if types < typesMin:
			typesMin = types
	if (1+B+1) < typesMin:
		typesMin = (1+B+1)
 
	return round(typesMin , 6)
	#return typesMin
 
if __name__ == "__main__":
	testcases = input()
 
	for caseNr in xrange(0, testcases):
		A, B = raw_input().split(" ")
		A = int(A)
		B = int(B)
		probabilities = line2floatlist(raw_input())
		#print ((A+1), B)
		#print probabilities
		print("Case #%i: %.6lf" % (caseNr+1, prob(A, B, probabilities)))
