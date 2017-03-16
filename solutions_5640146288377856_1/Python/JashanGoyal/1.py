import sys
sys.stdin=open('in','r')
sys.stdout=open('out','w')
for num in range(input()):
	r,c,w  =map(int,raw_input().split())
	if c!=w:
		if c%w==0:
			ans=r*(w-1+c/w)
		else:
			ans=r*(w+c/w)
	else:
		ans=r*w
	print "Case #"+str(num+1)+": "+str(ans)
	# print ans
