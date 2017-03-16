from sys import setrecursionlimit as slr
slr(10**9)

from random import getrandbits

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache: cache[args] = f(*args)
		return cache[args]
	return wrap

getl = lambda: raw_input().strip().split()
get = lambda: map(int, getl())


N = 32
J = 500

largestPrime = 2 ** ((N+1)/2)
primes = map(int, open('primes.in').read().split())
primes = [p for p in primes if p <= largestPrime]

def generateCoin(N, J):
	while True:
		number = '1' + ('{:0%db}' % (N-2)).format(getrandbits(N-2)) + '1'
		witnesses = []
		success = True
		for base in range(2, 10+1):
			witness = None
			n = int(number, base)
			for p in primes:
				if n % p == 0:
					witness = p
					break
			if witness is not None:
				witnesses.append(witness)
			else:
				success = False
				break
		if success:
			return number, witnesses
				


def getCoins(N, J):
	coins = dict()
	while len(coins) < J:
		coin, witnesses = generateCoin(N, J)
		if coin not in coins:
			coins[coin] = witnesses
	return coins

def solve(N, J):
	coins = getCoins(N, J)
	return '\n'.join('%s %s' % (coin, ' '.join(map(str, witnesses))) for coin, witnesses in coins.items())

print "Case #1:"
print solve(N, J)
