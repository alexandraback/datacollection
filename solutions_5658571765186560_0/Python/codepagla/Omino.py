t=int(input())

for i in xrange(1,t+1) :
	x,r,c=map(int,raw_input().split())
	win=False
	if x==1 :
		win=True
	elif x==2 :
		if not (r*c)%x :
			win=True
	elif x==3 :
		if (not (r*c)%x) and (r*c)>3 :
			win=True
	elif x==4 :
		if (not (r*c)%x) and (r*c)>8 :
			win=True
	if win :
		print "Case #%d:"%(i),"GABRIEL"
	else :
		print "Case #%d:"%(i),"RICHARD"
