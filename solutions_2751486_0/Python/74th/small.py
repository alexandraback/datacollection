#!/usr/bin/env python
# -*- coding: utf-8 -*-

testcase = input()

DEBUG = False

def p(string):
	if DEBUG :
		print string
def p2(string1,string2):
	if DEBUG :
		print str(string1) + ":" + str(string2)

def ans(q,string):
	print "Case #" + str(q+1) + ": " + str(string)

boinstr = "aiueo";
alfastr = "abcdefghijklmnopqrstuvwxyz"
boin = []
shiin = []

for n in xrange(len(boinstr)):
	boin.append(boinstr[n])
for n in xrange(len(alfastr)):
	if not alfastr[n] in boin :
		shiin.append(alfastr[n])

for q in xrange(testcase) :

	line = raw_input().split(' ')
	name = line[0]
	shin = int(line[1])

	nameLen = len(name)

	nameList = []

	for m in xrange(shin,nameLen+1):
		
		for s in xrange(0,nameLen-m+1): 
			subName = name[s:s+m]

			p(subName)

			shinNum = 0

			for s2 in xrange(m):
				if subName[s2] in shiin :
					shinNum += 1
				else :
					shinNum = 0

				if shinNum >= shin :
					#if not subName in nameList :
					p2("ok",subName)
					nameList.append(subName)
					break

	ans(q,len(nameList))
		
	
	
	
	
