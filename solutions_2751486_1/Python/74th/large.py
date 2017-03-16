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


	isShin = False
	startShin = -1
	shinList = []

	p2("name",name)
	
	for x in xrange(nameLen) :

		#p2("now",name[x])
		#p2("isShin",isShin)

		if name[x] in shiin :
			if not isShin :
				startShin = x
				isShin = True
			#p2( "check", x - startShin )
			if x - startShin == shin - 1 :
				shinList.append(startShin)
				#p2("shin_x",startShin)
				#p2("shin_n",name[startShin:startShin + shin])
					
				startShin += 1
		else:
			isShin = False

	
	p2("shinList",shinList)

	before = 0
	num = 0

	for l in shinList :
		back = l - before + 1
		front = nameLen - ( l + shin ) + 1
		num += back * front
		before = l + 1

		p2("back",back)
		p2("front",front)
		p2("num",back * front )
	
	ans(q,num)
	#break

		





	



		
		
	
	
	
	

