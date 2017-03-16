#!/usr/bin/env python

import sys
import numpy as np

t_n = int(sys.stdin.readline())

def translate(a):
	if a == '.': return 0
	if a == 'X': return 1
	if a == 'O': return 2
	if a == 'T': return 3

xList = map(np.uint32,[int('1111000000000000',4),int('111100000000',4),int('11110000',4),int('1111',4),int('1000100010001000',4),int('100010001000100',4),int('10001000100010',4),int('1000100010001',4),int('1000010000100001',4),int('0001001001001000',4)])
oList = map (lambda x: x << 1, xList)
for t_t in range(1, t_n+1):
    a = []
    for i in range(5):
    	a.append(sys.stdin.readline().strip())
    a = ''.join(a)
    pattern = np.uint32(0)
    for i in range(len(a)):
    	pattern *= 4
    	pattern += translate(a[i])
    
    xComp = map (lambda x: x & pattern == x, xList)
    xWin = True in xComp
    oComp = map (lambda x: x & pattern == x, oList)
    oWin = True in oComp
    if xWin:
    	print("Case #%d: X won" % t_t)
    elif oWin:
        print("Case #%d: O won" % t_t)
    elif '.' in a:
        print("Case #%d: Game has not completed" % t_t)
    else:
    	print("Case #%d: Draw" % t_t)

