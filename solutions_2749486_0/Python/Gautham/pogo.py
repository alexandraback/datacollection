import math
from heapq import *

def euclid(x,y,dx,dy):
	return math.sqrt((x-dx)*(x-dx) + (y-dy)*(y-dy))

t = input()
for i in range(t):
	dict = {}
	l = []
	x,y = map(int,raw_input().split())
	dict[0,0] = ''
	heappush(l,[1+euclid(1,0,x,y),(1,0),'E',1])
	heappush(l,[1+euclid(-1,0,x,y),(-1,0),'W',1])
	heappush(l,[1+euclid(0,1,x,y),(0,1),'N',1])
	heappush(l,[1+euclid(0,-1,x,y),(0,-1),'S',1])
	while(True):
		t = heappop(l)
		if(t[1][0] == x) and (t[1][1] == y):
			tx = x
			ty = y
			st = ''
			m = t[3]
			dict[tx,ty] = t[2]
			while not (tx==0 and ty == 0):
				st = dict[tx,ty] + st
				if(dict[tx,ty] == 'N'):
					ty = ty - m
				elif(dict[tx,ty] == 'S'):
					ty = ty + m
				elif(dict[tx,ty] == 'E'):
					tx = tx - m
				elif(dict[tx,ty] == 'W'):
					tx = tx + m
				m = m-1
			print "Case #"+str(i+1)+": "+st
			break
		elif (t[1][0],t[1][1]) in dict:
			continue
		else:
			m = t[3]
			n = m+1
			m = (m*(m+1))/2
			tx = t[1][0]
			ty = t[1][1]
			dict[tx,ty] = t[2]
			if not (tx+n,ty) in dict:
				heappush(l,[m+euclid(tx+n,ty,x,y),(tx+n,ty),'E',n])
				#print tx+n,ty
			if not (tx-n,ty) in dict:
				heappush(l,[m+euclid(tx-n,ty,x,y),(tx-n,ty),'W',n])
				#print tx-n,ty
			if not (tx,ty+n) in dict:
				heappush(l,[m+euclid(tx,ty+n,x,y),(tx,ty+n),'N',n])
				#print tx,ty+n
			if not (tx,ty-n) in dict:
				heappush(l,[m+euclid(tx,ty-n,x,y),(tx,ty-n),'S',n])
				#print tx,ty-n
	