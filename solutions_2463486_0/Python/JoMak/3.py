import math
def palin(s):
	s=str(s)
	for c in range(len(s)/2):
		if s[c]!=s[len(s)-1-c]:
			return False
	#print s
	return True

inp = file("C-small-attempt0.in");
out = file("3_small_out.txt",'w');
T=int(inp.readline())
for x in xrange(T):
	A,B= (map(int,inp.readline().split()))
	c=0
	for i in filter(palin,range(int(math.ceil(math.sqrt(A))),int(math.floor(math.sqrt(B))+1))):
		if palin(str(i**2))==True:
			c+=1
	out.write("Case #%d: %d\n"%(x+1,c))
inp.close()
out.close()