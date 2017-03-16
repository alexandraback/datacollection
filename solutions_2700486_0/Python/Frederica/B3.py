global top, num, v
def vis(x,y):
	return v[x+100][y+100]==num;
def flood(x,y):
	v[x+100][y+100]=num
t = int(raw_input())
v = [[0 for x in range(200)]for y in range(200)]
num = 0
for test in range(1,t+1):
	t -= 1
	n,x,y=map(int,raw_input().split())
	if (abs(x)<50) and (abs(y)<50):
		n -= 1
		tot = 0
		ans = 0
		for i in range(1<<n):
			num += 1
			top = 0
			flood(0,0)
			top += 2
			j = 0
			while (j < n):
				k = (i >> j) & 1
				if (k == 0):
					p = 0
					q = top
					while (q > 0) and (vis(p-1,q-1)==0):
						p-=1
						q-=1
					if (p==0) and (vis(1,top-1)==0):
						break
					flood(p,q)
					if (p == 0):
						top += 2
				else:
					p = 0
					q = top
					while (q > 0) and (vis(p+1,q-1)==0):
						p+=1
						q-=1
					if (p==0) and (vis(-1,top-1)==0):
						break
					flood(p,q)
					if (p == 0):
						top += 2
				j += 1
			if (j==n) and (vis(x,y)!=0):
				ans+=1
			if (j==n):
				tot+=1
	else:
		ans=0
		tot=1
	print "Case #%d: %.10lf"%(test,1.0*ans/tot)