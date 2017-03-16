def denom(coins, C, V):
	vals = [ '' ]

	for coin in coins:
		newVals = []

		for i in range(C + 1):
			for val in vals:
				newVals.append(val + str(i))

		vals = newVals

	values = set()

	for val in vals:
		value = 0
		for i in range(len(val)):
			value += int(val[i]) * coins[i]

		values.add(value)

	needed = []

	for v in range(V + 1):
		if v not in values:
			needed.append(v)
	
	# print needed

	if len(needed) < 2:
		return len(needed)

	memo = {}

	for n in needed:
		s = []

		for val in values:
			x = n - val
			if x > 0 and x not in coins:
				s.append(x)

		memo[n] = s

	newCoins = set()

	for n in memo:
		newCoins |= set(memo[n])

	# print newCoins

	memo2 = {}

	for coin in newCoins:
		memo2[coin] = sum([coin in memo[n] for n in memo])

	return 1 + denom(coins + [max(newCoins, key = lambda x: memo2[x])], C, V)

def main():
	from sys import stdin
	input = stdin.read().split('\n')
	T = int(input[0])

	for t in range(T):
		C, D, V = map(int, input[2 * t + 1].split())
		coins = map(int, input[2 * t + 2].split())

		print "Case #{0}: {1}".format(t + 1, denom(coins, C, V))

if __name__ == '__main__':
	main()