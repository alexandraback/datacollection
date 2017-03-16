#!/usr/bin/env python
# -*- coding: utf-8 -*-

testcase = input()

greats = []

def isGreat(num):
	strNum = str(num)
	kekka = True
	nagasa = len(strNum)
	for n in xrange( nagasa / 2 ):
		if strNum[n] != strNum[ nagasa-1-n ] :
			kekka = False
	return kekka

n = 1
greats = []
while n * n <= 1000 :
	if isGreat( n * n ) :
		greats.append(n * n)
	n = n + 1

#print greats

greats = [1, 4, 9, 121, 484]

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


