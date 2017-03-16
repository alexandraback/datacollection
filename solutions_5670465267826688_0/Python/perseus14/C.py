arr=	[[0,0,0,0,0],
	[0,1,2,3,4],
	[0,2,-1,4,-3],
	[0,3,-4,-1,2],
	[0,4,3,-2,-1]]
def con(s):
	if(s=='i'):
		return 2
	if(s=='j'):
		return 3
	if(s=='k'):
		return 4
	return s

def multiply(s,c):
	s=con(s)
	c=con(c)
	flag=False
	if(s<0):
		flag = not flag
		s=abs(s)
	if(c<0):
		flag = not flag
		c=abs(c)
	if(flag):
		return -arr[s][c]
	return arr[s][c]
		

T=input()
for t in xrange(1,T+1):
	L,n=map(int,raw_input().split())
	S=raw_input()*n
	k=1
	print "Case #%d:"%t,
	flag_i=False
	flag_j=False
	flag_k=False
	I=[]
	for x in xrange(len(S)):
		k=multiply(k,S[x])
		I.append(k)
	if(I[-1]!=-1):
		print "NO"
	else:
		for x in I:
			if(x==2 and not flag_i):
				flag_i=True
			if(x==4 and flag_i):
				flag_j=True
			if(x==-1 and flag_j):
				flag_k=True
		if(flag_i and flag_j and flag_k):
			print "YES"
		else:
			print "NO"
