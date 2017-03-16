#!/usr/bin/env python
# -*- coding: utf-8 -*-
import copy

testcase = input()

DEBUG = False

print "Case #1:"

def p(string):
	if DEBUG :
		print string
def p2(string1,string2):
	if DEBUG :
		print str(string1) + ":" + str(string2)

def ans(q,string):
	print "Case #" + str(q+1) + ": " + string


line = raw_input().split(' ')
R = int(line[0])
N = int(line[1]) #
M = int(line[2]) # 7
K = int(line[3]) # 7

p2("R",R)
p2("N",N)
p2("K",K)
p2("M",M)

testList = []
for n in range(222,556):
	n1 = n % 10
	n2 = (n/10)%10
	n3 = (n/100)%10

	dame = False
	for m in [n1,n2,n3] :
		if not( 2 <= m and m <= M ) :
			dame = True
			break
	if dame :
		continue

	if not ( n1 <= n2 and n2 <= n3 ) :
		continue
	testList.append( ( n1 , n2 , n3 ) )
	
ansList = {}
for test in testList :
	
	#p2("test",test)

	for n in xrange(8) :
		n1 = n % 2
		n2 = (n/2)%2
		n3 = (n/4)%2
		
		q = 1
		if n1 == 1:
			q = q * test[0]
		if n2 == 1:
			q = q * test[1]
		if n3 == 1:
			q = q * test[2]

		#p2("q",q)

		if not q in ansList :
			ansList[q] = {}
		
		if not test in ansList[q] :
			ansList[q][test] = 1
		else:
			ansList[q][test] += 1


for r in xrange(R) :

	line = raw_input().split(' ')
	check = []
	for k in xrange(K) :
		check.append( int(line[k]) )

	rei = copy.deepcopy(ansList[ check[0] ])

	p2("a",rei)
	
	for k in xrange(1,K):
		rei2 = ansList[check[k]]
		zyuhukunashi = []
		
		p2("k",check[k])
		p2("rei",rei)
		p2("rei2",rei2)

		for key,v in rei.items() :
			# 重複していなければ削除
			if not( key in rei2 ) :
				zyuhukunashi.append(key)
		
		p2("zyunashi",zyuhukunashi)

		for z in zyuhukunashi :
			del rei[z]

		# ポイント加算
		for key,v in rei2.items() :
			if key in rei :
				rei[key] += v

	p2("answermae", rei)
	maxpoint = 0
	answer = 0
	for key,v in rei.items() :
		if maxpoint < v :
			maxpoint = v
			answer = key
	
	p2("answer", answer)

	ansstr = ""
	for a in answer :
		ansstr += str(a)

	print ansstr
	

	

