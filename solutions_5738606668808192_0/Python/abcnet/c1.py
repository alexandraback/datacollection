import random
import sys
def convert(sn, base):
	s=0
	for i in sn:
		s*=base
		s+=eval(i)
	return s

def isPrime(n):
	i=2
	while i*i<=n:
		if n%i==0:
			return False
		i+=1
	return True

def smallestFactor(n):
	i=2
	while i*i<=n:
		if n%i==0:
			return i
		i+=1
	return -1

def toBase(n, base):
	s=[]
	while n>0:
		s.insert(0, str(n%base))
		n/=base
	return ''.join(s)
# print convert('11',2)
# print convert('11',3)
# print convert('11',4)
# print convert('11',5)
# print convert('11',10)
# print isPrime(2)
# print isPrime(3)
# print isPrime(6)
# print isPrime(7919)
# print isPrime(982451653)
# print isPrime(10000000000000000000000000001)
# print toBase(16,2)
# print toBase(2**32-1,2)
# print toBase(7**88-7,7)

f = open(sys.argv[1], 'r')
result = open(sys.argv[1]+'.sol','w')
T=eval(f.readline())
random.seed()

print 'T = ', T
for t in range(T):
	print "Case #", t+1
	result.write('Case #'+str(t+1)+':\n')
	N,J=tuple(map(eval,f.readline().split()))
	print N,J
	
	got=0
	low=2**(N-2)
	high=2**(N-1)-1
	while got<J:
		candidate=random.randint(low, high)*2+1
		b=toBase(candidate,2)
		eligible=True
		l=[0]*10
		l[0]=b
		for base in range(2,11):
			n=convert(b,base)
			small=smallestFactor(n)
			if small>-1:
				l[base-1]=str(small)
			else:
				eligible=False
		if eligible:
			result.write(' '.join(l)+'\n')
			# print l
			got+=1
			print 'Got ', got
			for base in range(2,11):
				n=convert(b,base)
				# print n, '=', l[base-1], '*', n/eval(l[base-1]), ', ', n%eval(l[base-1])
		

f.close()
result.close()

