def sqrt(a):
	b=0
	i=0
	s=1
	v=1
	while(s<=a):
		s<<=1
		i+=1
	i=i//2
	v<<=i
	s=1<<(2*i)
	rc=0;
	while(s>0):
		if(rc+2*v*b+s>a):
			v>>=1
			s>>=2
			continue
		rc+=s+2*v*b
		b+=v
		v>>=1
		s>>=2
	return b
n=int(input())
for i in range(n):
	rs=input().split()
	r=int(rs[0])
	t=int(rs[1])
	v=4*r*r-4*r+8*t+1;
	v2=2*r-1;
	v=sqrt(v)
	re=0
	if(v<v2): re=v2-v
	else: re=v-v2
	re=re//4
	print("Case #%d: %d"%(i+1,re))

