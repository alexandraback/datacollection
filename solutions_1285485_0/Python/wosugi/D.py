# coding: utf-8
import sys
import math

EPS = 0.000001

def distance(x1,y1,x2,y2):
	return math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))

def angle(x1,y1,x2,y2):
	return (math.degrees(math.atan2(y2-y1,x2-x1))+360.0)%360.0

def reachable(x0,y0,x,y,history):
	if x==x0 and y==y0:
		return False
	
	d = distance(x0,y0,x,y)
	if D+EPS<d:
		return False
	
	th = angle(x0,y0,x,y)
	for n in range(len(history)):
		if abs(history[n]-th)<=EPS:
			return False
	#print("({0},{1}) {2} {3}".format(x,y,d,th))
	history.append(th)
	return True

if __name__=='__main__':
	T = int(sys.stdin.readline())
	for tc in range(T):
		H,W,D = [int(it) for it in sys.stdin.readline().split()]
		field = []
		for j in range(H):
			field.append(sys.stdin.readline().rstrip('\n'))
		
		cols,rows = W-2,H-2
		x0,y0 = 0.0,0.0
		for j in range(H):
			for i in range(W):
				if field[j][i]=='X':
					x0,y0 = i-0.5,j-0.5
		#print((cols,rows))
		#print((x0,y0))
		
		ps = []
		for j in range(-D,+D+1):
			for i in range(-D,+D+1):
				ps.append((2*cols*i+x0,2*rows*j+y0))
				ps.append((2*cols*i-x0,2*rows*j+y0))
				ps.append((2*cols*i+x0,2*rows*j-y0))
				ps.append((2*cols*i-x0,2*rows*j-y0))
		#print(ps)
		
		ans = 0
		history = []
		for i in range(len(ps)):
			if reachable(x0,y0,ps[i][0],ps[i][1],history):
				ans += 1
		print('Case #{0}: {1}'.format(tc+1,ans))
