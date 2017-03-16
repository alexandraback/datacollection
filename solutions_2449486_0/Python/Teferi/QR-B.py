#Lawnmower
t=input()
for tt in range(t) :
	n,m=map(int,raw_input().split())
	l=[]
	for i in range(n) :
		l+=map(int,raw_input().split())

	out="YES"
	for i in range(n*m) :
		x=l[i/m*m:i/m*m+m]
		y=l[i%m:m*n:m]
		if not(max(x)==l[i] or max(y)==l[i]) :
			out="NO"
			break
	
	print "Case #%d: "%(tt+1)+out