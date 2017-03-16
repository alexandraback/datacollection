import concurrent.futures as cf


def possible(v, coins):
	if v == 0:
		return True
	for i, c in enumerate(coins):
		if c <= v and possible(v - c, coins[:i] + coins[i+1:]):
			return True
	return False
			

def calc(C, D, V, coins):
	res = 0
	for v in range(1, V+1):
		if not possible(v, coins):
			coins.append(v)
			res += 1
	return res


def main():
	T = int(input())
	results = []
	with cf.ProcessPoolExecutor(max_workers=8) as executor:
		for _ in range(T):
			C, D, V = [int(x) for x in input().split()]
			coins = [int(x) for x in input().split()]
			results.append(executor.submit(calc, C, D, V, coins))
	for cs, result in enumerate(results):
		print('Case #{}: {}'.format(cs + 1, result.result()))


if __name__ == '__main__':
	main()
