import concurrent.futures as cf


def calc(r, c, w):
	res = r * (c // w)
	if c % w:
		res += 1
	res += w-1
	return res


def main():
	T = int(input())
	results = []
	with cf.ProcessPoolExecutor(max_workers=8) as executor:
		for _ in range(T):
			r, c, w = [int(x) for x in input().split()]
			results.append(executor.submit(calc, r, c, w))
	for cs, result in enumerate(results):
		print('Case #{}: {}'.format(cs + 1, result.result()))


if __name__ == '__main__':
	main()
