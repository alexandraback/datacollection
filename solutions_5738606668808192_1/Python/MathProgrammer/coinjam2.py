from copy import*
from math import*

def primetest(N):
	global primes
	for p in primes:
		if p>sqrt(N):
			return 1
		if (N%p)==0:
			return p
	return 1

def generate(N):
	strings=[1]
	newstrings=[1]
	for i in range(N-2):
		newstrings=[]
		for s in strings:
			newstrings+=[10*s,10*s+1]
		strings=deepcopy(newstrings)
	for i in range(len(strings)):
		strings[i]*=10
		strings[i]+=1
	return strings

def baseconvert(n,b):
	ans=0
	factor=1
	while n>0:
		ans+=factor*(n%10)
		factor*=b
		n//=10
	return ans

def eratosthenes(limit):
	Z=[0]*(limit+1)
	Z[0]=1
	Z[1]=1
	primes=[]
	for i in range(2,limit+1):
		if Z[i]==0:
			primes.append(i)
			j=i*2
			while j<limit+1:
				Z[j]=1
				j+=i
	return primes

def convertback(N):
	factor=1
	ans=0
	while N>0:
		if N%2==1:
			ans+=factor
		factor*=10
		N//=2
	#print(ans)
	#print("################")
	return ans

def next(n):
	bn=baseconvert(n,2)
	bn+=2
	ans=convertback(bn)
	return ans
	

def SOLVE(N,J,casenumber,g):
	g.write("Case #{}:\n".format(casenumber))
	global primes
	cand=10**(N-1)+1
	#print(cand)
	succ=0
	while True:
		li=[0]*9
		for i in range(2,11):
			bn=baseconvert(cand,i)
			k=primetest(bn)
			if k>1:
				li[i-2]=k
			else:
				break
		if li[-1]>1:
			g.write("{} {} {} {} {} {} {} {} {} {}\n".format(cand,li[0],li[1],li[2],li[3],li[4],li[5],li[6],li[7],li[8]))
			#print(cand,[baseconvert(cand,i) for i in range(2,11)],li)
			succ+=1
		if succ==J:
			return
		cand=next(cand)
		#print(cand)
			

f=open("C-large.in","r")
g=open("google.out","w+")
T=int(f.readline())

primes=eratosthenes(92682)

for i in range(T):
	[N,J]=[int(i) for i in f.readline().split()]
	ans=SOLVE(N,J,i+1,g)
	#g.write("Case #{}: {}\n".format(i+1,ans))

g.close()
f.close()




