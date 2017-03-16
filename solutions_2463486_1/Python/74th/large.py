#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math

testcase = input()

greats = [1,4,9]

def isGreat(num):
	strNum = str(num)
	kekka = True
	nagasa = len(strNum)
	for n in xrange( nagasa / 2 ):
		if strNum[n] != strNum[ nagasa-1-n ] :
			kekka = False
	return kekka

def isSqrGreat(num):
	sqr = num * num
	if isGreat(sqr) :
		greats.append(sqr)

h = 1
for n in xrange(4) :
	#print "n:" + str(n)
	#print "h:" + str(h)
	for m in xrange(h,h*10) :
		#print "m:" + str(m)
		num = str(m)
		for x in xrange(n+1) :
			#print "x:" + str(x)
			num = num + num[n-x]
		isSqrGreat(int(num))
	for k in xrange(10):
		for m in xrange(h,h*10) :
			#print "m:" + str(m)
			num = str(m) + str(k)
			for x in xrange(n+1) :
				#print "x:" + str(x)
				num = num + num[n-x]
			#print num
			isSqrGreat(int(num))
	h = h * 10
	
for q in xrange(testcase) :

	line = raw_input().split(' ')
	A = int(line[0])
	B = int(line[1])

	#print (A,B)

	num = 0
	for g in greats :
		if A <= g and g <= B :
			num = num + 1

	print "Case #" + str(q+1) + ": " + str( num )
