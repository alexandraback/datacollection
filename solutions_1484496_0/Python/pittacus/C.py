def solve(a,b,sa,sb):
	#print [sa,sb]
	if sum(sa)==sum(sb) and sa!=sb: return [sa,sb]
	if len(a)==0 or len(b)==0: return []
	at=a.pop()
	bt=b.pop()
	
	r=solve(a,b,sa,sb) #[0,0]
	if r: return r
	sa.add(at)
	r=solve(a,b,sa,sb) #[1,0]
	if r: return r
	sb.add(bt)
	r=solve(a,b,sa,sb) #[1,1]
	if r: return r
	sa.discard(at)
	r=solve(a,b,sa,sb) #[0,1]
	if r: return r
	sb.discard(bt)
	a.add(at)
	b.add(bt)
	
	return []

for N in range(input()):
	s=map(int,raw_input().split())
	a=s[1:]
	b=set(a)
	a=set(a)
	m=solve(a,b,set(),set())
	#print m
	print "Case #%d:" % (N+1)
	print " ".join(map(str,list(m[0])))
	print " ".join(map(str,list(m[1])))
	#m=["%.6f" % (100.0*t) for t in m]
	#print "Case #%d: %s" % (N+1, " ".join(m))
	