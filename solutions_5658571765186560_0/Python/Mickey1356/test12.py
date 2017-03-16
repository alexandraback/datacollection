def decide(r,c,x):
	if x>=7:
		return 'RICHARD'
	else:
		if (r*c)%x != 0:
			return 'RICHARD'

		if x==1:
			return 'GABRIEL'
		if x==2:
			if (r*c)%2==1:
				return 'RICHARD'
			else:
				return 'GABRIEL'
		if x==3:
			if r==1 or c==1:
				return 'RICHARD'
			if r*c<=3:
				return 'RICHARD'
			else:
				return 'GABRIEL'
		if x==4:
			if r==1 or c==1:
				return 'RICHARD'
			if r*c <= 8:
				return 'RICHARD'
			else:
				return 'GABRIEL'

		if x==5:
			if r==1 or c==1:
				return 'RICHARD'
			if r*c <= 15:
				return 'RICHARD'
			else:
				return 'GABRIEL'

		if x==6:
			return None

inp=open('in.in','r')
f=open('out.out', 'w')
t=int(inp.readline().strip('\n'))
# t=input()
for tc in range(1,t+1):
	# x,r,c=map(int,raw_input().split())
	x,r,c=map(int, inp.readline().strip('\n').split())
	ans=decide(r,c,x)
	f.write("Case #"+str(tc)+": "+str(ans)+"\n")
	# print "Case #%i: %s" % (tc, ans)
