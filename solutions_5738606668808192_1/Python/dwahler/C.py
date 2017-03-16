import sys, random

raw_input()
N, J = map(int, raw_input().split())

divisor_limit = 100

# find primes, slow and simple
primes = [2]
for i in xrange(3, divisor_limit):
	if all(i%p != 0 for p in primes):
		primes.append(i)


# find coins
results = {}
bits = ['0', '1']
while len(results) < J:
	candidate = '1' + ''.join(random.choice(bits) for i in xrange(N-2)) + '1'
	if candidate in results:
		continue

	is_valid = True
	divisors = []

	for base in xrange(2, 11):
		value = int(candidate, base)
		found_divisor = False

		for d in primes:
			if value % d == 0:
				divisors.append(d)
				found_divisor = True
				break

		if not found_divisor:
			is_valid = False
			break

	if is_valid:
		results[candidate] = divisors

print "Case #1:"
for candidate, divisors in sorted(results.items()):
	print candidate, ' '.join(str(d) for d in divisors)
	