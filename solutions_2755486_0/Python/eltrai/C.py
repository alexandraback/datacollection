#!/usr/bin/python

from bisect import bisect_left, bisect_right

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(N):
	tribes = []
	for i in range(N):
		d,n,w,e,s,dd,dp,ds = readarray(int)
		for j in range(n):
			if s >= 0:
				tribes.append((d,w,e,s))
			d += dd
			w += dp
			e += dp
			s += ds
	tribes.sort()
	
	breach_c = 0
	lastday = -1
	wall = None
	newwall = [(-300,0),(300,0)]
	for d,w,e,s in tribes:
		breached = False
		if d != lastday:
			#print("New day : ", d)
			wall = newwall
			newwall = wall[:]
			#print("Wall construction ended")
			#print(wall)
		#print("Attack from", w, e, "with strenght", s)		
		lastday = d
		b = list(map(lambda c : c[0], wall))
		i = bisect_right(b, w)-1
		j = bisect_left(b, e)
		for wi in range(i,j):
			if wall[wi][1] < s:
				breached = True
				break
		if breached:
			breach_c += 1
			#print("Attack successful")

		b = list(map(lambda c : c[0], newwall))
		#print(b)
		i = bisect_right(b, w)-1
		j = bisect_left(b, e)
		#print(i, j)
		corr = 0
		for wio in range(i,j):
			wi = wio + corr
			if newwall[wi][1] < s :
				#print("Breached on ", wi)
				if wi+1 < len(newwall) and newwall[wi+1][0] > e:
					newwall.insert(wi+1, (e, newwall[wi][1]))
					#print("Insert EndofAttack")
				if newwall[wi][0] < w:
					newwall.insert(wi+1, (w, s))
					#print("Insert BeginofAttack")
					corr += 1
				else:
					newwall[wi] = (newwall[wi][0], s)
					#print("Changed height")
			#print("New Wall : ", newwall)
	#print(wall)
	return breach_c
	

cases = readint()
for k in range(cases):
	N = readint()
	print('Case #' + str(k+1) + ': ' + str(solve(N)))
