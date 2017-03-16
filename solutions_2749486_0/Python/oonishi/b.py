# coding: cp932
import sys
import math

f   = file(sys.argv[1])
out = file(sys.argv[1][:-3] + '.out', 'w')

caseCnt = int(f.readline())



for case in range(1, caseCnt+1):
	X, Y = map(int, f.readline().split())
	
				
	if X > 0:
		ew = 'WE'*X
	else:
		ew = 'EW'*-X
	
	if Y > 0:
		ns = 'SN'*Y
	else:
		ns = 'NS'*-Y
	
	print>>out, 'Case #%d:'%case, ew+ns
		
		
'''
		s = s[1:]
		cnt += 1
		E = (cnt, x+cnt, y, path+'E')
		W = (cnt, x-cnt, y, path+'W')
		N = (cnt, x, y+cnt, path+'N')
		S = (cnt, x, y-cnt, path+'S')
				
		e = E
		if (e[1], e[2]) == (X, Y):
			break
		e = W
		if (e[1], e[2]) == (X, Y):
			break
		e = N
		if (e[1], e[2]) == (X, Y):
			break
		e = S
		if (e[1], e[2]) == (X, Y):
			break
			
		s += [E, W, N, S]
	print>>out,  'Case #%d:'%case, e[3]
'''
	
	