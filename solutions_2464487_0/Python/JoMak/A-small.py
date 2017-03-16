import math
inp=file("A-small-attempt0.in");
out=file("A-small-out.txt",'w');
T=int(inp.readline().strip())
for aa in range(T):
	r,t=map(int,inp.readline().split())
	#print str(r)+" "+str(t)
	ring=0
	while(t-((r+1)**2-r**2)>=0):
		#print t
		t-=((r+1)**2-r**2)
		r+=2
		ring+=1
	out.write("Case #%d: %d\n"%(aa+1,ring))
inp.close()
out.close()