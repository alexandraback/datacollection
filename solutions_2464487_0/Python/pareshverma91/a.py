
def even(r,t):
	s=0; e=4*10**18;
	bar=(int((r-1)/2)*(5+(r-1)**2-(r-2)**2))/2
	ans=0
	while s<=e:
		m=int((s+e)/2)
		cur=5+4*m
		ar=((m+1)*(5+cur))/2
		ar-=bar
		if ar<=t:
			ans=m+1-int((r-1)/2)
			s=m+1
		else:
			e=m-1
	return ans

def odd(r,t):
	s=0; e=4*10**18;
	bar=(int(r/2)*(3+(r-1)**2-(r-2)**2))/2
	ans=0
	while s<=e:
		m=int((s+e)/2)
		cur=3+4*m
		ar=((m+1)*(3+cur))/2
		ar-=bar
		if ar<=t:
			ans=m+1-int(r/2)
			s=m+1
		else:
			e=m-1
	return ans

t=int(input())
for i in range(1,t+1):
	r,t=input().split()
	r=int(r); t=int(t)
	ans=0;
	if r%2==0:
		ans=even(r,t)
	else:
		ans=odd(r,t)
	s="Case #"+str(i)+": "+str(ans)
	print(s)
