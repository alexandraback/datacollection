_=input()
for tc in xrange(1,_+1):
	n,j=map(int,raw_input().split())
	print "Case #%d:"%(tc)
	for i in xrange(j):
		r=2**(n-1)+2**(n/2)+2**(n/2-1)+1+i*2+i*2**(n/2+1)
		print str(bin(r))[2:],
		for base in xrange(2,11):
			print base**(n/2)+1,
		print