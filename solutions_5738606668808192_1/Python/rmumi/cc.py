import math

prime=[]
isprime=[(i%2) for i in range(0,1<<17)]
pwr=[[pow(b,i) for i in range(0,33)] for b in range(0,11)]

def sito():
	prime.append(2)
	isprime[2]=1
	for x in range(3,1<<16,2):
		if isprime[x]:
			prime.append(x)
			for l in range(x*x,1<<16,2*x):
				isprime[l]=0


def firstDiv(num): #not completely true for big numbers...
	for x in prime:
		if x*x>num:
			break
		if num%x==0:
			return x
	return 0

def toBase(num,b):
	br=0
	for i in reversed(range(0,len(pwr[b]))):
		br=br*10
		br+=int(num/pwr[b][i])
		num%=pwr[b][i]
	return br

def toBaseFrom2(num,b):
	br=0
	for i in (range(0,len(str(num)))):
		br+=(str(num)[-(i+1)]=='1')*pwr[b][i]
	return br


if __name__ == "__main__":

	sito()

	inp=open('in.txt','r')

	t=int(inp.readline())
	n,m=[int(x) for x in inp.readline().split()]

	poc=(1<<(n-1))+1;

	l=[0 for i in range(11)]

	print 'Case #1:'

	u=0;

	x=poc

	while x<(1<<n):
		nije=0
		if u==m:
			break
		broj=toBase(x,2)
		for b in range(2,11):
			num=toBaseFrom2(broj,b)
			l[b]=firstDiv(num)
			if l[b]==0:
				nije=1
				break
		if nije==0:
			u+=1
			print broj,
			for i in range(2,11):
				if i!=10:
					print l[i],
				else:
					print l[i]
		x+=2





