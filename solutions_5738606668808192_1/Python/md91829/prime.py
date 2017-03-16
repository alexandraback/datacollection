import math

def isNotPrime(n):
	i=2
	j=n/2
	while(i<25):
		f=1
		k=n
		mod =0
		while(k>0):
			d=k%10
			mod=(mod + ((d%i) * (f%i))%i)%i
			f=f*10
			k=k/10
		#print i,mod
		if(mod==0):
			return i
		i+=1
	return -1

t=input()
k=1
while(t):
	t-=1
	l=map(int,raw_input().split())
	n=l[0]
	j=l[1]
	print "Case #" ,k, ": "
	k+=1
	i=1
	#print isNotPrime(123)
	while(j>0):
		if(isNotPrime(i)!=-1):
			s = '{0:030b}'.format(i)
			s = "1" + s + "1"
			#print s
			a=list()
			flag=0;
			for x in range(2,11):
				num=0
				for c in range(0,len(s)):
					if(s[c]=='1'):
						num+=(pow(x,len(s)-c-1))
				w=isNotPrime(num)
				if(w==-1):
					flag=1
					break
				else:
					a.append(w)
			if(flag==0):
				j-=1
				print s,
				for m in a:
					print m,
				print
		i+=2
			
