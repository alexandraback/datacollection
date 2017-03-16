import sys

from math import *
from itertools import *
from collections import defaultdict

F = '.'

def lg(a) :
    sys.stderr.write(str(a)+"\n")

def fillFrom(m,xC,yC,cnt,val) :
    x,y = xC,yC
    while cnt>0 :
	m[y][x] = val
	x += 1
	if x>=len(m[0]) :
	    x = 0
	    y += 1
	    if y>= len(m) and cnt>1 :
		raise Exception("too many cells")
	cnt -= 1
    return m,x,y

def dump(m) :
    return "\n".join( "".join(l) for l in m )

def sol(r,c,free) :
    m = [ [ "*" for x in range(c) ] for y in range(r) ]

    if r==1 or c==1 :
	poss = True
	m,_,_ = fillFrom(m,0,0,free,F)
    elif r==2 or c==2 :
	if free==1 :
	    poss = True
	else :
	    poss = (free%2)==0 and free>2
	    if poss :
		n = free/2
		if r==2 :
		    for i in range(n) :
			m[0][i] = F
			m[1][i] = F
		else :
		    for i in range(n) :
			m[i][0] = F
			m[i][1] = F
    else :
	poss = True
	if free in (2,3,5,7) :
	    poss = False
	else :
	    cnt = free
	    x = 0
	    y = 0
	    while cnt>=2 and x<c :
		m[0][x] = F
		m[1][x] = F
		x += 1
		cnt -= 2
	    if cnt>0 and free>1 :
		y = 2
		x = 0
		m,x2,y2 = fillFrom(m,x,y,cnt,F)
		# print 1 ; print dump(m)
		if x2==1 :
		    last = c-1
		    if m[y2-1][last]=='*' :
			last -= 1
		    # print last
		    m[y2][1] = F
		    m[y2-1][last] = '*'
		    # print 2 ; print dump(m)
		    if y2==2 :
			m[0][last] = '*'
			m[y2][2] = F
		    # print 3 ; print dump(m)
    if not poss :
	return "Impossible"

    m[0][0] = "c"

    f = 0
    for l in m :
	for b in l :
	    if b=='.' :
		f += 1
    if f!=(free-1) :
	print ">",f,free,r,c,r*c-free
	assert False

    return dump(m)

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    r,c,m = map(int,sys.stdin.readline().split())
    free = r*c-m
    print "Case #%d:" % testNr
    print sol(r,c,free)
