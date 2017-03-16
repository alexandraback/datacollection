import sys

primes = [2]
def sieve(top):
	global primes
	not_prime = [0] * top
	for p in range(3, top, 2):
		if not not_prime[p]:
			primes.append(p)
			for p2 in range(2*p, top, p):
				not_prime[p2] = 1
	sys.stderr.write('Sieve done. Found %d primes. %d, %d\n' % (len(primes), primes[1], primes[-1]))

def try_factor(x):
	for p in primes:
		if p >= x: return 0
		if x % p == 0:
			return p
	return 0

def solve(i):
	N, J = map(int, sys.stdin.readline().split())
	B = (1 << (N-1)) + 1
	found = 0
	for i in xrange(0, 1 << (N-1), 2):
		num = "{0:b}".format(B + i)
		factors = []
		for base in xrange(2,11):
			f = try_factor(int(num, base))
			if f == 0:
				break
			else:
				factors.append(f)
		if len(factors) == 9:
			print num, ' '.join(map(str, factors))
			found += 1
			if found == J:
				return

if __name__ == '__main__':
	sieve(10000000)
	c = int(sys.stdin.readline())
	for i in range(c):
		print 'Case #%d:' % (i+1,)
		solve(i)
