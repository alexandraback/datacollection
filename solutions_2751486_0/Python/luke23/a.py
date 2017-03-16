c = int(input())

def f(st,l):
	b=[0]*(len(st))
	for x in range(0,len(st)-l+1):
		z=0
		for p in range(0,l):
			if st[p+x] in ["a","e","i","o","u"]:
				z=1
				break
		if z==0:
			b[x]=1
	s=0
	for x in range(0,len(st)-l+1):
		p=x
		while p<len(b) and b[p]==0:p+=1
		if p==len(b):
			break
		s+=len(st)-p+1-l
	return s






for x in range(c):
	v=raw_input().split()
	n=f(v[0],int(v[1]))
	print ("Case #"+str(x+1)+": "+str(n))