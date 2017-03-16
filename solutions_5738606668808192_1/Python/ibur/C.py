import sys

primes = [2]

def prime(x):
	for p in primes:
		if x % p == 0:
			return False
		if p * p > x:
			return False
	return True

def parse(mask, base):
	res = 0
	p = 1
	for i in range(0, 32):
		if mask & (1 << i):
			res += p
		p *= base
	return res

counter = 3
for i in range(100000):
	if prime(counter):
		primes.append(counter)
	counter += 2

sys.stderr.write('done primegen\n')

def check(m):
	for b in range(2, 11):
		if prime(parse(m, b)):
			return False
	return True

def print_mask(m):
	print bin(m)[2:],
	for b in range(2, 11):
		val = parse(m, b)
		for i in range(len(primes)):
			if val % primes[i] == 0:
				print primes[i],
				break
	print ''

print "Case #1:"
j = 0
count = 0
for m in xrange(0x80000001, 0x100000000, 2):
	count += 1
	if check(m):
		print_mask(m)
		j+=1
		if j == 500:
			sys.exit(0)


