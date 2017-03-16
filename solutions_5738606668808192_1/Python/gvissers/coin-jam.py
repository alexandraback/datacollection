#!/usr/bin/python3

def genIsPrime(pmax):
	pend = pmax + 1
	is_prime = pend * [True]
	is_prime[0] = is_prime[1] = False
	for i in range(2, pend):
		if is_prime[i]:
			for j in range(i*i, pend, i):
				is_prime[j] = False
	return is_prime

def genPrimesAndIsPrime(pmax):
	is_prime = genIsPrime(pmax)
	primes = [p for p in range(pmax+1) if is_prime[p]]
	return primes, is_prime

def div(n, primes, is_prime):
	if n < len(is_prime) and is_prime[n]:
		return None
	for p in primes:
		if n % p == 0:
			return p
	return None

pmax = (1 << 16)
primes, is_prime = genPrimesAndIsPrime(pmax)

t = int(input())
for icase in range(1, t+1):
	n, j = map(int, input().split())
	print('Case #1:')
	for i in range(1 << (n-2)):
		s = '1' + bin(i)[2:].zfill(n-2) + '1'
		divs = []
		for b in range(2, 11):
			m = int(s, b)
			d = div(m, primes, is_prime)
			if d is None:
				break
			divs.append(d)
		else:
			print(s + ' ' + ' '.join(map(str, divs)))
			j -= 1
			if j == 0:
				break
