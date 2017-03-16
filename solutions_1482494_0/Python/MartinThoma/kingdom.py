#!/usr/bin/python
# -*- coding: utf-8 -*-

from copy import deepcopy

def line2intlist(line):
    list = line.split(' ')
    numbers = [ int(x) for x in list ]
    return numbers

def king(case, starDict, myLevel = 0, myCompetes = 0, partially = [], recursion = 0):
	somethingChanged = True
	while somethingChanged:
		remove = []
		somethingChanged = False
		#all where i can do both
		for index in starDict:
			one, two = starDict[index]
			if two <= myLevel:
				remove.append(index)
				somethingChanged = True

		#remove them
		for index in remove:
			myCompetes += 1
			if index in partially:
				myLevel += 1
				partially.remove(index)
			else:
				myLevel += 2
			del starDict[index]

	wasInFor = False
	#print "bbbbbbbbbbbb-2"
	minmaxLevel = 50000
	minmaxIndex = -1

	maxminLevel = 50000
	maxminIndex = -1

	"""
	# min-approach
	for index in starDict:
		wasInFor = True
		one, two = starDict[index]
		if one <= myLevel and one < minmaxLevel:
			minmaxLevel = one
			minmaxIndex = index
	# max-approach
	for index in starDict:
		wasInFor = True
		one, two = starDict[index]
		if one <= myLevel and one < maxminLevel:
			maxminLevel = one
			maxminIndex = index
	"""
	for index in starDict:
		wasInFor = True
		one, two = starDict[index]
		if one <= myLevel and one < minmaxLevel:
			minmaxLevel = one
			minmaxIndex = index

	#print "Recursion " + str(recursion)
	if wasInFor:
		#print "b"
		if minmaxIndex == -1:
			#print (case, myLevel, starDict, partially)
			return "Too Bad"
		minCompetes = 100000000
		for index in starDict:
			one, two = starDict[index]
			if one <= myLevel:
				starDictTmp = deepcopy(starDict)
				partiallyTmp = deepcopy(partially)
				partiallyTmp.append(index)
				tmpCompetes = king(case, starDictTmp, myLevel+1, myCompetes+1, partiallyTmp, recursion+1)
				if tmpCompetes != "Too Bad" and tmpCompetes < minCompetes:
					minCompetes = tmpCompetes
		if minCompetes == 100000000:
			#print (case, myLevel, starDict, partially, "aaaaaaaaaaa")
			return "Too Bad"
		myCompetes = minCompetes

		#min-approach
		##starDictMin = deepcopy(starDict)
		##partiallyMin = deepcopy(partially)
		##partiallyMin.append(minmaxIndex)
		##minCompetes = king(starDictMin, myLevel+1, myCompetes+1, partiallyMin, recursion+1)
		#max-approach
		##starDictMax = deepcopy(starDict)
		##partiallyMax = deepcopy(partially)
		##partiallyMax.append(maxminIndex)
		##maxCompetes = king(starDictMax, myLevel+1, myCompetes+1, partiallyMax, recursion+1)

		##myCompetes = min(minCompetes, maxCompetes)



	return myCompetes

 
if __name__ == "__main__":
	testcases = input()
 
	for caseNr in xrange(0, testcases):
		levels = input()
		stars = []
		for i in xrange(0, levels):
			stars.append(line2intlist(raw_input()))

		#make stars dictionary
		starDict = {}
		level = 1
		for el in stars:
			starDict[level] = el
			level += 1

		print("Case #%i: %s" % (caseNr+1, king(caseNr+1, starDict)))
