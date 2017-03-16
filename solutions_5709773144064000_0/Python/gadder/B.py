T=input()
for i in range(T):
	s=raw_input();
	(C,F,X)=map(float, s.strip().split(' '))
	r=2
	minTime=X/r
	t=0
	while 1:
		tt=C/r
		t=t+tt
		r=r+F
		newTime=t+X/r
		if newTime<minTime:
			minTime=newTime
		else:
			break
	print 'Case #'+str(i+1)+': '+str(round(minTime,7))
