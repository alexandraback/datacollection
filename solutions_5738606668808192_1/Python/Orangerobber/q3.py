import sys
from math import sqrt

T = int(sys.stdin.readline().strip())

def divisor(n):
	j = 2
	while j**2 <= n and j < 1e5:
		if n % j == 0:
			return j
		j += 1
	return None

def bin2base(bin,base):
	return sum([base**i * bin[i] for i in range(len(bin))])

def check_coin(coin):
	isGood = True
	divisors = []
	for base in range(2, 11):
		d = divisor(bin2base(coin,base))
		if d is None:
			return None
		divisors.append(d)
	return divisors

def loop_coins(N,J):
	count = 0
	current = 0
	while count < J:
		binary = ('1{0:0%db}1'%(N-2)).format(current)
		coin = [int(x) for x in reversed(binary)]
		divisors = check_coin(coin)
		if divisors is None:
			current += 1
			continue
		else:
			count += 1
			print binary,
			for d in divisors:
				print d,
			print ""
		current += 1

for t in range(T):
	N,J = [int(x) for x in sys.stdin.readline().strip().split()]
	print "Case #1:"
	loop_coins(N,J)


