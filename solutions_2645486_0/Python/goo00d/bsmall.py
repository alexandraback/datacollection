import sys

def solve(E,start,energy):
	global R,N,tt,res,yuanR
	if start>=N:
		if energy>res:
			res=energy
		return
	for i in xrange(R,E+1):
		tmpEnergy=energy+i*tt[start]
		tmpE=min(E,E-i+yuanR)
		solve(tmpE,start+1,tmpEnergy)



fp=open('B-small-attempt3.in','r')
sys.stdin=fp
ll=input()
fout=open('outb.txt','w')
sys.stdout=fout
for ttcase in range(ll):
	E,R,N=map(int,raw_input().split(" "))
	yuanR=R
	tt=map(int,raw_input().split(" "))
	R=min(R,E)
	maxenergy=0
	res=0
	solve(E,0,maxenergy)
	print "Case #%d:"%(ttcase+1),res

fp.close()
fout.close()