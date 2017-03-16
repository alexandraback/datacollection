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

def ansshow(q,string):
	print "Case #" + str(q+1) + ": " + str(string)

def check(x,y,root):
	nowx = 0
	nowy = 0
	rootLen = len(root)
	for s in xrange(rootLen) :
		ashi = root[s]
		if ashi == "N" :
			nowy += s+1
		if ashi == "S" :
			nowy -= s+1
		if ashi == "W" :
			nowx -= s+1
		if ashi == "E" :
			nowx += s+1
	return nowx == x and nowy == y 
	
for q in xrange(testcase) :
	
	line = raw_input().split(' ')
	qx = int(line[0])
	qy = int(line[1])

	ans = ""

	if qx > 0 :
		myqx = qx
		rqx = True
		ans += "WE" * myqx
	else :
		myqx = -1 * qx
		rqx = False
		ans += "EW" * myqx
	if qy > 0 :
		myqy = qy
		rqy = True
		ans += "SN" * myqy
	else :
		myqy = -1 * qy
		rqy = False
		ans += "NS" * myqy

	# まず、Xに近づく
	#ans += "SN" * myqx
	#ans += "WE" * myqy
	p2("ans",ans)

	p2("qx",qx)
	p2("qy",qy)
	p2("check",check(qx,qy,ans))

	ansshow(q,ans)

	
	
	
		
	
	
