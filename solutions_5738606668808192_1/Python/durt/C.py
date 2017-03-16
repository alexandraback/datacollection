import sys

def coinBase(coin, b):
	res = 0
	p = 1
	while (coin > 0):
		if (coin % 2 == 1):
			res += p
		p *= b
		coin /= 2
	return res

def findFactor(n):
	j = 2
	while (j*j <= n) and (j <= 10): # don't waste time on "maybe"-primes
		if (n % j == 0):
			return j;
		j += 1
	return -1

print "Case #1:"
N = 32
J = 500

cnt = 0
i = 0
while i < 2**(N-2):
	coin = 2**(N-1) + 2*i + 1
	ok = True
	proof = [None] * 11
	for b in range(2, 10 + 1):
		val = coinBase(coin, b)
		proof[b] = findFactor(val)
		if (proof[b] == -1):
			ok = False
			break
		#print "coin=" + str(coin) + " " + str(coinBase(coin, 10)) + " ..."
	if ok:
		print coinBase(coin, 10),
		for b in range(2, 10 + 1):
			print proof[b],
		else:
			print
		sys.stdout.flush()
		cnt += 1
	if (cnt == J):
		break
	i += 1

