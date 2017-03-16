import random

def random_str():
	result = '1'
	for i in range(N-2):
		result += str(random.randint(0,1))
	result += '1'
	
	return result

def legitimate(jamcoin):
	result = jamcoin
	for i in range(2,11):
		n = int(jamcoin, i)
		factor = findfactor(n)
		if 0 == factor:
			return None
		else:
			result += ' ' + str(factor)

	return result + '\n'

def findfactor(n):
	#assert primes[-1]*primes[-1]>n
	for p in primes:
		if p*p>n:
			return 0
		if n%p==0:
			return p
	return 0


if __name__ == '__main__':
	f = open('primes.txt','r')
	input = open('input.txt','r')
	output = open('output.txt','w')

	primes = [int(i) for i in f.read().split()]
	primes = primes[:1000]
	[T,N,J] = [int(i) for i in input.read().split()]
	
	j=0
	output.write('Case #1:\n')
	while(j<J):
		jamcoin = random_str()
		result = legitimate(jamcoin)
		if None == result:
			continue
		output.write(result)
		j+=1
	

