# A

import sys

def g(n, i):
	global C
	return C[n[0]][n[1]][i]

def s(n, i, v):
	global C
	C[n[0]][n[1]][i] = v

def check(f, t):
	global H, N, M, C, ni
	
	#print 'check ', C, f, t
	
	if g(t,2) == 0: return
	if g(f,1) + 50 > g(t,0): return
	if g(t,1) + 50 > g(t,0): return
	if g(t,1) + 50 > g(f,0): return

	tm = g(f, 2)
	h = H - 10 * tm
	if h + 50 > g(t,0): # need time
		tm += float(h + 50 - g(t, 0)) / 10
	elif g(f, 2) == 0:
		s(t, 2, 0)
		ni.append(t)
		return

	h = H - 10 * tm
	if h >= g(f,1) + 20:
		tm += 1
	else:
		tm += 10
	if g(t, 2) == -1 or tm < g(t, 2):
		s(t, 2, tm)
		ni.append(t)
	

T = int(sys.stdin.readline())

for t in xrange(1, T+1):
	H,N,M = map(int,sys.stdin.readline().split())
	C = list()
	for i in range(N):
		C.append([ [int(x), 0, -1] for x in sys.stdin.readline().split()])
	for i in range(N):
		c = map(int, sys.stdin.readline().split())
		for j in range(M):
			C[i][j][1] = c[j]

	ni = [[0, 0],]
	s(ni[0], 2, 0)
	while len(ni)>0:
		nn = ni
		ni = list()
		for n in nn:
			#print n
			if n[0]>0: check(n, [ n[0]-1, n[1] ])
			if n[1]>0: check(n, [ n[0], n[1]-1 ])
			if n[0]<N-1: check(n, [ n[0]+1, n[1] ])
			if n[1]<M-1: check(n, [ n[0], n[1]+1 ])
	
	#print C
			
	print 'Case #%d: %f' % (t, C[N-1][M-1][2])
	
