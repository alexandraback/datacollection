from decimal import *

def feq(x,y):
	return abs(x-y)<1e-6
	
def solveQ(d,v0,a):
	#print d,v0,a
	if v0<1e-6:
		return (d/a)**Decimal(0.5)
	B=Decimal(v0)
	C=Decimal(-d)/B
	A=a*Decimal(0.5)/B
	
	D=1-4*A*C
	assert(D>0)
	D=D**Decimal(0.5)
	return Decimal((D-1)/2/A)

def solve(D,Ns,a):
	#print '>>',D,Ns,a
	Xt=[0]*(len(Ns)+1)
	Vt=[0]*(len(Ns)+1)
	for k in range(len(Ns)):
		(t,x)=Ns[k]
		if k>0:
			(t_1,x_1)=Ns[k-1]
		else:
			(t_1,x_1)=(0,0)
		dt=t-t_1
		dx=x-x_1
		
		if x>D:
			if k==0:
				#print 'SOLVE EQ'
				return solveQ(D,0,a)
			t=(D-x_1)*dt/dx+t_1
			x=D
			#print 'RELOC',t,x
		xt=Xt[k]+Vt[k]*dt+a*dt*dt*Decimal(0.5)
		vt=Vt[k]+a*dt
		if xt>x:
			assert(k>0)
			Xt[k+1]=x
			Vt[k+1]=dx/dt
			#print 'BRAKE',k,Xt[k+1],Vt[k+1]
			if feq(x,D): return t
		else:
			Xt[k+1]=xt
			Vt[k+1]=vt
			if feq(x,D):
				#print 'SOL',D,Xt[k],Vt[k],a
				return t_1+solveQ(D-Xt[k],Vt[k],a)
		
for T in range(input()):
	s=raw_input().split()
	D=Decimal(s[0])
	N=int(s[1])
	A=int(s[2])
	Ns=[map(Decimal,raw_input().split()) for n in range(N)]
	print "Case #%d:" % (T+1)
	for a in map(Decimal,raw_input().split()):
		 print "%.8f" % float(solve(D,Ns,a))