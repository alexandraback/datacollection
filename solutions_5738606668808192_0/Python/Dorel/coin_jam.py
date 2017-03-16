from math import sqrt
import random 

def prime_factor(n) :
        s=int(sqrt(n))+1
        if (n==3 or n==2) : return 1
        elif (n%2==0) : return 2
        else :
                p=3
                while (p< s) :
                        if (n%p==0) : return p
                        else : p+=2
                if (p*p>n) : return 1

def base(n, b) :
	return sum([ b**(len(n)-1-i) for i in xrange(len(n)) if (n[i]=='1')])
	
f=open("input")
T=f.readline()
N,J = [ int(x) for x in f.readline().strip().split()]

samples={}
while (len(samples)<J):
	x = '1' + ''.join([ random.choice(['0','1']) for x in xrange(N-2)]) + '1'
	if (prime_factor(int(x))!=1 and not x in samples.keys()) :
		divisors = []
		for i in xrange(2,10): 
			div=prime_factor(base(x,i))
			if (div!=1) : divisors.append(div)
			else : break
		if (len(divisors)==8) : 
			samples[x]= divisors + [prime_factor(int(x))]
		else : continue
print("Case #1:")
for x in samples :
	print x, samples[x][0], samples[x][1], samples[x][2], samples[x][3], samples[x][4], samples[x][5], samples[x][6], samples[x][7], samples[x][8]
