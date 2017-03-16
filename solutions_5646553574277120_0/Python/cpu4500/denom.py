import numpy as np

def sum_coins(b, coins):
	s = 0
	for i in xrange(len(coins)):
		if b[i] == '1':
			s += coins[i]

	return s

def mark_denoms(num, coins, v):
	lenc = len(coins)
	lim = pow(2, lenc)

	for n in xrange(1, lim):
		b = bin(n)[2:][::-1]
		# pad with zeros
		b += "0" * (lenc - len(b))
		idx = sum_coins(b, coins) - 1
		if idx >= v:
			break # numbers will not get smaller

		num[idx] = 0

	return num

def calc_denoms(coins, c, v):
	num = [ 1 ] * v
	added = 0

	# fill the number up to denoms
	num = mark_denoms(num, coins, v)
	left = np.count_nonzero(num)
	while left > 0:
		for i in xrange(v):
			if num[i] == 0:
				continue

			coin = i + 1
			coins.append(coin)
			coins.sort()
			added += 1

			num = mark_denoms(num, coins, v)
			left = np.count_nonzero(num)
			break # recalc left

	return added

if __name__ == '__main__':
	import sys
	import time

	start_time = time.time()

	data = file(sys.argv[1], "rb").read()
	lines = data.split('\n')
	out = file(sys.argv[1] + "-sol.dat", "wb")

	for i in xrange(int(lines[0])):
		c, d, v = lines[2*i+1].strip().split(" ")
		c = int(c)
		d = int(d)
		v = int(v)
		coins = [int(x) for x in lines[2*i + 2].strip().split(" ")]
		if len(coins) != d:
			raise Exception("invalid input")

		coins.sort()
		out.write("Case #%d: %d\n" % (i + 1, calc_denoms(coins, c, v)))

	out.close()
	print "--- %s seconds ---" % (time.time() - start_time)
