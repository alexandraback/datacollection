def solve(ass,As,bs,Bs):
	if len(As)==0 or len(Bs)==0: return 0
	if As[0]==Bs[0]:
		t=min(ass[0],bs[0])
		ass[0]-=t
		bs[0]-=t
		if ass[0]==0:
			ass=ass[1:]
			As=As[1:]
		if bs[0]==0:
			bs=bs[1:]
			Bs=Bs[1:]
		return t+solve(ass,As,bs,Bs)
	else:
		return max(solve(ass[1:],As[1:],bs,Bs),solve(ass,As,bs[1:],Bs[1:]))
		

for T in range(input()):
	(N,M)=map(int,raw_input().split())
	Ns=map(int,raw_input().split())
	ass=[Ns[k] for k in xrange(len(Ns)) if k%2==0]
	As=[Ns[k] for k in xrange(len(Ns)) if k%2==1]
	Ms=map(int,raw_input().split())
	bs=[Ms[k] for k in xrange(len(Ms)) if k%2==0]
	Bs=[Ms[k] for k in xrange(len(Ms)) if k%2==1]
	#print (ass,As,bs,Bs)
	print "Case #%d: %d" % (T+1,solve(ass,As,bs,Bs))