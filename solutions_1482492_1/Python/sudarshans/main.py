from __future__ import division
from math import sqrt

def acctillcollide(initSpeed,initTime,initDist,index):
	#index indicates how far we are along the journey, index->index+1 segment being entered
	#print initSpeed,initTime,initDist,index
	while True:
		if index==len(x)-1:
			#last segment reached earlier
			if initDist>=d:
				return initTime
			else:
				dst=d-initDist
				return (sqrt(initSpeed*initSpeed+2*ca*dst)-initSpeed)/ca+initTime
		timeLag=t[index+1]-initTime #time till next hit
		deltaDist=initSpeed*timeLag+0.5*ca*timeLag*timeLag
		if x[index+1]>d:
			#we end halfway through the run!
			newDelta=d-initDist
			timeWe=(sqrt(initSpeed*initSpeed+2*ca*newDelta)-initSpeed)/ca+initTime
			timeHe=(d-x[-2])/(x[-1]-x[-2])*(t[-1]-t[-2])+t[index]
			return max(timeWe,timeHe)
		newDist=deltaDist+initDist
		if newDist>x[index+1]:
			#we've hit in between
			#can reach the end at same time as him
			#print "hit,stopping"
			lvspd=max((x[index+1]-x[index])/(t[index+1]-t[index]),sqrt(2*ca*(x[index+1]-x[index])))
			initSpeed=lvspd
			initDist=x[index+1]
			initTime=t[index+1]
			index+=1
			continue
		else:
			#continue
			#print "movin at %f"%ca
			initSpeed=initSpeed+timeLag*ca
			initTime=t[index+1]
			initDist=newDist
			index+=1
			continue

def case():
	vals=raw_input().split()
	global d,n,x,t,ca
	d=float(vals[0])
	n=int(vals[1])
	x=[]
	t=[]
	for i in xrange(0,n):
		ct,cx=map(float,raw_input().split())
		x.append(cx)
		t.append(ct)
	a=map(float,raw_input().split())
	for ca in a:
		print acctillcollide(0,0,0,0)

numcases=int(raw_input())
for i in xrange(0,numcases):
	print "Case #%d:"%(i+1)
	#case specific code here
	case()
