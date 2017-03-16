#!/usr/bin/python
# -*- coding: utf-8 -*-

import psyco
psyco.full()
 
testcases = input()
 
def line2intlist(line):
	list = line.split(' ')
	numbers = [ int(x) for x in list ]
	return numbers
 
def skalarproduct(v1, v2):
	sum = 0
	for i in xrange(0, len(v1)):
		sum += v1[i]*v2[i]
	return sum

def getAnswer(classDict, N):
	for startPoint in xrange(1, N):
		reachable = [startPoint]
		justAppended = [startPoint]
		while len(justAppended) > 0:
			newJustAppended = []
			for node in justAppended:
				#print node
				for new in classDict[node]:
					if new in reachable:
						return "Yes"
					else:
						newJustAppended.append(new)
						reachable.append(new)
			justAppended = newJustAppended
	return "No"
 
for i in xrange(0, testcases):
	N = input()
	classDict = {}
	for classNr in xrange(1, N+1):
		liste = line2intlist(raw_input())
		classDict[classNr] = liste[1:]
	print("Case #%i: %s" % (i+1, getAnswer(classDict, N)))

