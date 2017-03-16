# -*- coding: utf-8 -*-
import sys
import math

# 一行読む
def ReadL():
	return sys.stdin.readline()[0:-1]

# 一行読んでINTにする
def ReadLInt():
	return int(ReadL())


# スペースで区切って一行読む
def ReadLSplit():
	return ReadL().split(' ')

# さらにINT型にする
def ReadLSplitInt():
	return [int(x) for x in ReadLSplit()]

# 回答を出力する
def PrintA(q,out):
	print 'Case #'+str(q+1)+': '+str(out)

# 回答を出力する
def PrintAArray(q,array):
	st = ''
	for s in array:
		st += str(s) + ' '
	PrintA(q,st)

# 回答を出力する
def PrintAArrayWithKakko(q,array):
	st = ''

	if len (array)== 0 :
		PrintA(q,'[]')
		return

	for s in array:
		st += str(s) + ', '
	PrintA(q,'['+st[:-2]+']')

# 標準エラー出力
def ShowEr(value):
	sys.stderr.write(str(value)+"\n")

# 問題番号出力
def ShowQueNum(q):
	ShowEr("---question:"+str(q+1)+"---")

# 簡単出力
def ShowData(name,d):
	ShowEr(str(name)+" :"+str(d))

# 簡単列出力 
def ShowListData(name,d):
	out = ""
	for o in d:
		out +=","+str(o)
	ShowData(name,out[1:])

# 括弧付き列出力
def ShowKakkoTsukiListData(name,alist):
	out = "["
	for o in alist :
		out +=","+str(o)

qNum = ReadLInt()

debugMode = False

def dprint(str):
	if debugMode :
		print str

for q in xrange(qNum):
	
	L = ReadLInt()

	req = {}
	req = []
	for l in xrange(L):
		req.append( ReadLSplitInt() )
		
	# まず、star2の数字の小さい順に並べる
	for i in xrange(L):
		for j in xrange(i,L):
			if req[i][1] < req[j][1] :
				buf = req[i]
				req[i] = req[j]
				req[j] = buf
	
	#for i in xrange(L):
	#	dprint(req[i])
	dprint(req)
	
	get = 0
	ans = 0
	req1 = []
	req2 = req

	while True :

		bstar = get
		nreq1 = []
		nreq2 = []
		saitei = 9999999999999

		dprint(req1)
		dprint(req2)

		dprint("star1")

		#star1とれる問題を探す
		num = len(req1)
		for l in xrange(num):
			star1 = req1.pop(0)
			
			if star1[1] <= get :
				get = get + 1
				ans = ans + 1
			else :
				if star1[0] < saitei :
					saitei = star1[1]
				nreq1.append(star1)

		dprint("star2")
		req1 = nreq1

		#star2とれる問題を探す
		num = len(req2)
		for l in xrange(num):
			star2 = req2.pop(0)
			dprint("req2:" + str(star2) + ",get:" + str(get) )
			
			if star2[1] <= get :
				dprint("ans!")
			
				get = get + 2
				ans = ans + 1
			else :
				if star2[1] < saitei :
					saitei = star2[1]
				nreq2.append(star2)
				
		req2 = nreq2

		#star2とれる問題を探す
		if bstar == get :
			dprint("star2,1")
			num = len(req2)
			bget = get
			for l in xrange(num):
				star2 = req2.pop(0)
				dprint("req2:" + str(star2) + ",get:" + str(get) )
				
				if star2[0] <= bget :
					dprint("ans!")
				
					get = get + 1
					ans = ans + 1
					req1.append(star2)
					if saitei >= get :
						break
				else :
					nreq2.append(star2)
				
			#req1 = nreq1
			req2 = nreq2

		if bstar == get :
			break

	if len(req1) == 0 and len(req2) == 0 :
		PrintA(q,ans) 
	else :
		PrintA(q,"Too Bad") 

