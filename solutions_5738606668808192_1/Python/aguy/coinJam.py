import random
import itertools

def primesBelow(n):
	isPrime = [1]*n
	isPrime[0] = isPrime[1] = 0

	ans = []
	for i, iPrime in enumerate(isPrime):
		if iPrime:
			ans.append(i)
			current = 2  * i
			while current < n:
				isPrime[current] = 0
				current += i
	return ans

#print(len(primesBelow(100000)))

primes = primesBelow(10000)

def hasDivisor(x):
	if (is_probable_prime(x)): return False
	for p in primes:
		if p == x: return False
		if x%p == 0:
			return p
	return False

def f(s):
	ans = []
	for i in range(2,11):
		x = hasDivisor(int(s, i))
		if not x:
			return False
		ans.append(x)
	return ' '.join(map(str,ans))





#source https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Python:_Probably_correct_answers
def is_probable_prime(n):
    assert n >= 2
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
        return False
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n-1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2**s * d == n-1)
 
    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True # n is definitely composite
 
    for i in range(10):
        a = random.randrange(2, n)
        if try_composite(a):
            return False
 
    return True # no base tested showed n as composite


n = 32
j = 500

print("Case #1:")
for i in itertools.product('01', repeat = n - 2):
	s = '1' + ''.join(i) + '1'
	x = f(s)
	if x:
		print(s + ' ' + x)
		j -= 1
		if j == 0:
			break