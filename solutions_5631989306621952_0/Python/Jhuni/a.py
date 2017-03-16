T = int(input())
for TT in range(1,T+1):
	d = input()
	x=""
	l=len(d)
	x+=d[0]
	mx=d[0]
	for i in range(1,l):
		if d[i] >= mx:
			x=d[i]+x
			mx=d[i]
		else:
			x=x+d[i]
	print("Case #%d: %s" % (TT,x))
