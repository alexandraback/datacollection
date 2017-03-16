import fileinput

f=fileinput.input()
T=int(f.readline())
g=open('output','w')

def solve(P,Q,est):	
	if(est>40 or (Q!=1 and Q%2==1)):
		return "Impossible"	
	if(P==Q or P==0):
		return str(est)
	elif(2*P<=Q):
		return solve(P,Q/2,est+1)
	else:
		if(solve(P-Q/2,Q/2,est)!="Impossible"):
			return str(est+1)
		else:
			return "Impossible"


for l in range(T):
	line=(f.readline())
	j=0
	while(line[j]!='/'):
		j=j+1
	P=int(line[:j])
	Q=int(line[j+1:])
	dum=Q	
	s=0
	while(dum%2!=1):
		s=s+1
		dum=dum/2
	t=Q/pow(2,s)
	if(P%t==0):		
		ans=solve(P/t,pow(2,s),0)
	else:
		ans="Impossible"
	g.write( 'Case #'+str(l+1)+': '+ans+"\n")
