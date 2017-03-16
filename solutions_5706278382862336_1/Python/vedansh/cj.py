from fractions import gcd
def chk(b):
	while(b%2==0):
		b=b/2
	if b==1:
		return 1
	else:
		return -1


t=input()
for i in xrange(t):
	a,b=map(int,raw_input().split('/'))
	c=gcd(a,b)
	a=a/c
	b=b/c
	if(chk(b) == -1):
		print "Case #%d: impossible" %(i+1)
		continue
	for j in xrange(1,41):
		if (2**j*a-b>=0):
			print "Case #%d: %d" %(i+1,j)
			break
		if j == 40:
			print "Case #%d: impossible" %(i+1)
	
	
