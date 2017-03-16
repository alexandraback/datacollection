from __future__ import division

numcases=int(raw_input())
for i in xrange(0,numcases):
	print "Case #%d:"%(i+1),
	vals=map(int,raw_input().split())
	#vals[i] is the score of ith contestant
	vals=vals[1:]

	x=sum(vals)
	n=len(vals)

	for j in vals:
		ans=100*(2/n-j/x)
		ans=ans if ans>0.0 else 0.0
		print ans,
	print
