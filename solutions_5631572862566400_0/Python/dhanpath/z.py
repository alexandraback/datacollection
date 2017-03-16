import sys
sys.stdin = open( "in", "r" )
sys.stdout = open( "out", "w" )

from itertools import permutations as per

def chk( x ):
	x = [x[-1]] + list(x) + [ x[0] ]
	d = 0
	for i in range(1,len(x)-1):
		if d == 0 :
			if a[x[i]] != x[i+1] :
				d = 1
		else:
			if a[x[i]] != x[i-1] :
				return 0
	return 1

for t in range(input()):
	print "Case #"+str(t+1)+":",
	n = input()
	a = [0] + map( int, raw_input().split() )
	myPer = [ i for i in range(1,n+1) ]
	ans = 1
	for L in range(2,n+1):
		for x in per(myPer,L):
			if chk(x):
				ans = L
				break
		if ans < L :
			break
	print ans