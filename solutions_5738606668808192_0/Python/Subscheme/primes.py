
UPPER_BOUND = 2 ** 16 + 1

sieve = [True] * UPPER_BOUND
sieve[0] = False
sieve[1] = False

primes = []

for i in range(UPPER_BOUND):
	if sieve[i]:
		primes.append(i)
		j = 2 * i
		while j < UPPER_BOUND:
			sieve[j] = False
			j += i

print ' '.join(map(str, primes))
