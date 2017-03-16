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

# さらにINT型にする
def ReadLSplitFloat():
	return [float(x) for x in ReadLSplit()]

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
	
	( st , sts ) = ReadLSplitInt()

	p = ReadLSplitFloat()

	dprint( q)

	# 打ち続けた場合
	prob = 1
	for i in xrange( st ) :
		prob = prob * p[i]

	strokeL = sts - st + 1
	strokeW = sts - st + 1 + sts + 1
	kitai = strokeL * prob + strokeW * ( 1 - prob )

	dprint( "全部打つ:" + str(kitai) )

	ans = kitai

	# バックスペースをst回押す
	strokeL = 2 * st + sts - st + 1
	kitai = strokeL
	dprint( "BS" + str(st) + ":" + str(kitai) )

	if kitai < ans :
		ans = kitai

	# 即ENTER 
	kitai = 1 + sts + 1
	dprint( "即" + ":" + str(kitai) )

	if kitai < ans :
		ans = kitai

	# バックスペース
	prob = 1
	for n in xrange(0,st - 1) :
		#dprint(n)
		a = st - n - 1
		
		#dprint( "BS" + str(a) + ":" + str(kitai) )
		prob = prob * p[ n ]
		dprint( "prob" + str(p[n]) + "=" + str(prob) ) 

		strokeL = 2 * a + sts - st + 1
		strokeW = strokeL + sts + 1

		kitai = strokeL * prob + strokeW * ( 1 - prob )
		dprint( "BS" + str(a) + ":" + str(kitai) )

		if kitai < ans :
			ans = kitai
	
	PrintA(q,ans)

		
	
