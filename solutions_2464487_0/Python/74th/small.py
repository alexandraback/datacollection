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


for q in xrange(testcase) :

	line = raw_input().split(' ')
	shiro = int(line[0])
	ink = int(line[1])

	flg = True

	useink = 0

	#First
	shiro_hankei = shiro
	kuro_hankei = shiro_hankei + 1

	#塗った回数
	nutta = 0

	while flg :
		# 白分
		shiro_menseki = shiro_hankei * shiro_hankei
		p2("白",shiro_menseki)
		# 黒分
		kuro_menseki = kuro_hankei * kuro_hankei
		p2("黒",kuro_menseki)

		use =  kuro_menseki - shiro_menseki
		useink = useink + use
		p2("使用料",useink)

		if useink > ink :
			ans(q,nutta)
			break

		nutta += 1
		shiro_hankei += 2
		kuro_hankei += 2

	
