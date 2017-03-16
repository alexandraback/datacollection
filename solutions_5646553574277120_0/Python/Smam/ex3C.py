import fileinput
import sys
import math

def has_representation(value, coins, max_per_coin):
	if value == 0:
		return True
	elif len(coins) == 0:
		return False
	elif coins[0] > value:
		return False
	else:
		for i in range(0,max_per_coin + 1):
			if has_representation(value - i * coins[0], coins[1:], max_per_coin):
				return True
		return False


def ex3C(line):
	(c,d,v) = [int(x) for x in line.split()]
	coins = [int(x) for x in sys.stdin.readline().rstrip().split()]
	res = 0
	for value in xrange(1, v+1):
		if not has_representation(value, coins, c):
			coins.append(value)
			coins = sorted(coins)
			res += 1
	return res

if __name__ == '__main__':
	ncases = int(sys.stdin.readline())
	for i in range(1, ncases + 1 ):
		print "Case #{0}: {1}".format(i, ex3C(sys.stdin.readline().rstrip()))
    	

    	
