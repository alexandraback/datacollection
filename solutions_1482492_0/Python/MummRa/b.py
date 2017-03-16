
import sys, string, math, bisect
from decimal import Decimal
from itertools import permutations
rl = lambda: sys.stdin.readline().strip()

for cs in xrange(1,int(rl())+1):
	ll=rl().split()
	d=Decimal(ll[0])
	n=int(ll[1])
	a=int(ll[2])
	
	car=[]
	for nn in xrange(n):
		car.append( tuple([Decimal(z) for z in rl().split()]) )
	accs=[Decimal(z) for z in rl().split()]
	
	answer=""
	for aa in accs:
		ans=-1
		mypos=Decimal(0.0)
		myv=Decimal(0.0)
		for q in xrange(len(car)-1):
			t,x=car[q]
			t1,x1=car[q+1]
			
			deltat=t1-t
			carv=(x1-x)/deltat
			
			#print "car",t,x,t1,x1,deltat,carv
			
			if x1>=d:
				#car crosses line at:
				dt=(d-x)/carv
				carlinetime=t+dt
				#print "CAR HAS CROSSED LINE at", carlinetime
				myposwhencarcrossesline=mypos+myv*dt+Decimal(0.5)*aa*dt**2
				if myposwhencarcrossesline>d: # we're stuck behind the car as it crosses the line
					#print "STUCK"
					ans=carlinetime
					break
				else:
					#print "NOTSTUCK"
					#we're not slowed by the car when it crosses the line so
					#solve quadratic
					aaa=Decimal(aa/2)
					bbb=Decimal(myv)
					ccc=Decimal(mypos-d)
					dt=(-bbb+Decimal(math.sqrt(bbb**2 - Decimal(4)*aaa*ccc)))/(Decimal(2)*aaa)
					ans=t+dt
					break
			#print 'hi!'
			mypotentialpos=mypos+myv*deltat+Decimal(0.5)*aa*deltat**2
			if mypotentialpos <= x1:
				mypos=mypotentialpos
				myv=myv+aa*deltat
			else:
				mypos=x1
				myv=carv
			#print "me at time", t1,mypotentialpos, mypos, myv, carv
		#print 'ans', ans
		#print
		answer+="\n" + str(ans)
	print "Case #{0}:{1}".format(cs,answer)
		