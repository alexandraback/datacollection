import sys
import time


class PrimeException(Exception):
	pass


def isprime(n):
	# 0 and 1 are not primes
	if n < 2:
		return False

	# 2 is the only even prime number
	if n == 2:
		raise PrimeException()

	# all other even numbers are not primes
	if not n & 1:
		return "2"

	# only test the lowest numbers
	prmlist = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
	for x in prmlist:
		if n % x == 0:
			return str(x)

	raise PrimeException()


def get_base2_str(x, totlen):
	s = ""
	d = "01"
	while x > 0:
		s = d[x % 2] + s
		x /= 2

	# include pad
	return "0" * (totlen - len(s)) + s


def print_jamcoins(n, j):
	coins = {}
	middle = 0
	while len(coins) < j:
		strcoin = "1%s1" % get_base2_str(middle, n - 2)
		nums = [int(strcoin, x) for x in xrange(2, 11)]
		try:
			factors = [isprime(x) for x in nums]
			coins[strcoin] = factors
			if len(coins) % 5 == 0:
				print "have %d coins" % len(coins)
		except PrimeException:
			pass

		middle += 1

	s = ""
	for c, f in coins.iteritems():
		s += "%s %s\n" % (c, " ".join(f))

	return s

if __name__ == '__main__':
	start_time = time.time()

	data = file(sys.argv[1], "rb").read()
	lines = data.split('\n')
	out = file(sys.argv[1] + "-sol.dat", "wb")

	for i in xrange(int(lines[0])):
		n, j = lines[i+1].split(" ")
		n = int(n)
		j = int(j)
		out.write("Case #%d:\n%s" % (i + 1, print_jamcoins(n, j)))

	out.close()
	print "--- %s seconds ---" % (time.time() - start_time)
