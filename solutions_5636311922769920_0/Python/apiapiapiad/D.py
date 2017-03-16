_=input()
for tc in xrange(1,_+1):
	k,c,s=map(int,raw_input().split())
	print "Case #%d:"%(tc),
	ret=[]
	x=0
	for i in xrange(k):
		x=x*k+i
		if i%c==c-1:
			ret.append(x+1)
			x=0
	if x!=0:
		ret.append(x+1)
	if len(ret)==0:
		ret.append(1)
	if len(ret)<=s:
		print " ".join(map(str,ret))
	else: print "IMPOSSIBLE"
