import random,time,math,sys

def isprime(n):
	d, r = n-1, 1
	while not d&1:
		d >>=1
		r  += 1
	for i in xrange(0,1000):
		a = random.randint(1, n-1)
		x = pow(a, d, n)
		if x == 1 or x == n-1:
			continue
		for j in xrange(1,r):
			x = pow(x,2,n)
			if x == 1:
				return False, factor(n, a)
			if x == n-1:
				break			
		else:
			return False, factor(n, a)
	return True, 0

def gcd(a,b):
	if b==0:return a
	return gcd(b,a%b)

def factor(n,a):
	d = n - 1
	while not d&1:
		d >>=1
	while d < n:
		g = gcd(pow(a,d, n)-1,n)
		if g > 1 and g < n:
			return g
		d *= 2
	return 1


def gcd(a,b):
	 if b==0:return a
	 return gcd(b,a%b)
	
def f(n, j):
	m = n - 2
	low = int('1' + m*'0' + '1', 2)
	high =  int('1'*n, 2)
	count = 0
	while low < high:
		b = bin(low)[2:]
		low += 2
		nums = map(lambda x:int(b, x), xrange(2,11))
		q = [b]
		for num in nums:
			prime, factor = isprime(num)
			if not prime and factor > 1 and num%factor == 0:
				q.append(factor)
			else:
				break
		else:
			print ' '.join(map(str, q))
			count +=1
			if count == j:break

count = 0
total = None
for line in sys.stdin:
	line = line.strip()
	if (total == None):
		total = int(line)
		continue
	count += 1
	print "Case #%s:"%count
	f(*map(int, line.split(' ')))
	if count == total:
		break

