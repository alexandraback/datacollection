def count_all(x,tar):
	i=0
	l=len(tar)
	count=0
	for y in xrange(len(x)):
		if(x[y]==tar[i]):
			i+=1
			i%=l
			if(i==0):
				count+=1
		else:
			i=0
	return count

def all_p(key,p,n,k):
	if(k==0):
		Ans.append(p)
		return
	for i in xrange(n):
		np=p+key[i]
		all_p(key,np,n,k-1)

def all1(key,k):
	n=len(key)
	all_p(key,"",n,k)


T=input()
for t in xrange(1,T+1):
	Ans=[]
	K,L,S=map(int,raw_input().split())
	Key=raw_input()
	Target=raw_input()
	all1(Key,S)
	count=0
	m=0
	for x in Ans:
		if(Target in x):
			z=count_all(x,Target)
			count+=z
			m=max(m,z)
	print "Case #%d:"%t,
	print "%0.7f"%(m-(count/(float(len(Ans)))))		
