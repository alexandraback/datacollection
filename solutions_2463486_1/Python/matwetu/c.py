import math
def fsqrt(x):
	l=1
	r=x
	while(l+1<r):
		m=(l+r)/2
		if m*m>x:
			r=m
		else:
			l=m
	return l
def csqrt(x):
	l=0
	r=x
	while(l+1<r):
		m=(l+r)/2
		if m*m<x:
			l=m
		else:
			r=m
	return r



#print fsqrt(1000000000000000000001**2)
#print fsqrt(1000000000000000000001**2+1)
#print fsqrt(1000000000000000000001**2-1)
#
#print csqrt(1000000000000000000001**2)
#print csqrt(1000000000000000000001**2+1)
#print csqrt(1000000000000000000001**2-1)


dic=[{} for i in range(11)];

def go(mk,l,ub):
#	print "go(%r, %d, %d) " % (mk,l,ub)
	ret=0;
	if(mk == None):
		if(dic[ub].has_key(l)):return dic[ub][l];
		if(l==0):
			ret=1;
			dic[ub][l]=ret;
			return ret;
		if(l==1):
			for i in range(10):
				if(i*i*l<=ub):
					ret+=1;
			dic[ub][l]=ret;
			return ret;
		for i in range(10):
			if i*i*2<=ub:
				ret+=go(None, l-2, ub-i*i*2)
		dic[ub][l]=ret;
		return ret;
	if(l==1):
		nm=int(mk);
		for i in range(nm+1):
			if i*i<=ub:
				ret+=1
		return ret;
	if(l==2):
		nm=int(mk);
		for i in range(10):
			if i*11<=nm and i*i*2<=ub:
				ret+=1;
		return ret;
	tmk=mk[1:-1];
	md=int(tmk);
	cost=int(mk[0]);
	cost=cost*cost*2;
	if mk[0]>mk[-1]:
		md-=1;
	if md>=0 and cost<=ub:
		ret+=go(str(md).zfill(l-2),l-2,ub-cost);
	for i in range(int(mk[0])):
		if(i*i*2<=ub):
			ret+=go(None,l-2,ub-i*i*2)
	return ret;

def cal2(mk,ub=9):
	ret=0;
	l=len(mk);
	if(l==1):
		nm=int(mk);
		for i in range(nm+1):
			if i*i<=ub:
				ret+=1
		return ret;
	if(l==2):
		nm=int(mk);
		for i in range(1,10):
			if i*11<=nm and i*i*2<=ub:
				ret+=1;
		return ret;
	tmk=mk[1:-1];
	md=int(tmk);
	cost=int(mk[0]);
	cost=cost*cost*2;
	if mk[0]>mk[-1]:
		md-=1;
	if md>=0 and cost<=ub:
		ret+=go(str(md).zfill(l-2),l-2,ub-cost);
	for i in range(1,int(mk[0])):
		if(i*i*2<=ub):
			ret+=go(None,l-2,ub-i*i*2)
	return ret;

def cal(x):
	if(x==0):return 1;
	tx=str(x);
#	print "cal",x
	ret = cal2(tx);
	for i in range(1,len(tx)):
		ret += cal2(str(10**i-1));
	return ret;

def solve(t,a,b):
	tb=fsqrt(b);
	ta=csqrt(a);
	print "Case #%d: %d" % (t,cal(tb)-cal(ta-1));

pa = lambda x:str(x)==str(x)[::-1]
sa = lambda x:pa(x*x)
sy = filter(sa,filter(pa,range(10**7)))
#print sy

def solveslow(t,a,b):
	print "Case #%d:" % t,
	print len(filter(lambda x:x*x>=a and x*x<=b, sy))

T=int(raw_input())
for cas in range(T):
	a,b=map(int,raw_input().split())
	#solve(cas+1,a,b);
	solveslow(cas+1,a,b);

