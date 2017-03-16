fin=open('C-large.in','r')
T=int(fin.readline())
N, J = map(int,fin.readline().strip().split(' '))

from numpy.random import randint
# T = 1
# N = 16
# J = 50

file('C-large.out','w')
f=open('C-large.out','w')
# file('C-test','w')
# f=open('C-test','w')

def randcoin(N):
	coin = ''
	for i in xrange(N-2):
		coin += str(randint(0,2))
	return '1'+coin+'1'

def gen_primes(n):
	nums = range(2,n+1)
	primes = []
	for i in xrange(n-1):
		if nums[i]:
			p = nums[i]
			primes.append(p)
			while p <= n-primes[-1]:
				p += primes[-1]
				nums[p-2] = False
	return primes

print 'generating primes ...'
primes = gen_primes(10**6)
primeh = {p:True for p in primes}

def maybe_prime(n):
	if n in primeh:
		return True, None
	for p in primes:
		if n%p == 0:
			return False, p
	return True, None

def jamcoin(coin):
	divs = [coin]
	for b in xrange(2,11):
		prime, div = maybe_prime(int(coin,b))
		if prime:
			return False
		else:
			divs.append(str(div))
	return divs

for time in xrange(T):
	print 'looking for jamcoins ...'
	count = 0
	div_list = []
	h = {}
	i = 0
	while count < J and i < 10**6:
		i += 1
		coin = randcoin(N)
		if coin not in h:
			h[coin] = True
			divs = jamcoin(coin)
			if divs:
				div_list.append(divs)
				count += 1
	print 'found %d jamcoins in %d iterations' %(count, i)
	f.write('Case #'+str(time+1)+':\n')
	for i in xrange(J):
		f.write(' '.join(div_list[i])+'\n')
		# print ' '.join(div_list[i])

f.close()