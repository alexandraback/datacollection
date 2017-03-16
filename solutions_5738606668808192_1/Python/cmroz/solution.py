import random
import math

def sieve(n):
	ret = []
	for i in xrange(2,n):
		if all(i % p != 0 for p in ret):
			ret.append(i)
	return ret

def convert(xs,base):
	b = 1
	ret = 0
	for i in xrange(len(xs)):
		ret += b * xs[i]
		b *= base
	return ret

def factorize(x,primes):
	if x in primes:
		return None
	for p in primes:
		if x % p == 0:
			return p
	return None

def guessCoin(nbits, primes):
	bits = [random.randint(0,1) for i in xrange(nbits)]
	bits[0] = 1
	bits[nbits-1] = 1

	nums = [convert(bits,k) for k in xrange(2,11)]
	factors = [factorize(x, primes) for x in nums]

	if all(x is not None for x in factors):
		return (bits, factors)
	else:
		return None

def check(bits, factors):
	print "bits = " + str(bits)
	for k in xrange(2,11):
		num = convert(bits,k)
		fac = factors[k-2]
		ok = (num % fac == 0) and (fac != 1 and fac != num)
		print "-> %d / %d: %s" % (num, fac, "ok" if ok else "nope")
		assert ok

def check_file(fn):
	def toBit(c):
		return {"0": 0, "1": 1}[c]

	lines = open(fn).readlines()
	for i in range(1,len(lines)):
		xs = lines[i].split(" ")
		bits = map(toBit, reversed(xs[0]))
		factors = map(int, xs[1:])
		assert len(factors) == 9
		check(bits,factors)

if __name__ == '__main__':
	ps = sieve(1 << 16)

	T = int(raw_input())
	for t in range(T):
		print "case #%d:" % (t+1)
		(N,J) = map(int, raw_input().split())
		seen = set()
		while J > 0:
			tmp = guessCoin(N,ps)
			if tmp is None:
				continue
			(bits, factors) = tmp
			if tuple(bits) in seen:
				continue
			seen.add(tuple(bits))
			a = "".join(map(str, reversed(bits)))
			b = " ".join(map(str, factors))
			print "%s %s" % (a,b)
			J -= 1
