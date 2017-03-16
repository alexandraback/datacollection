import concurrent.futures as cf


def calc(data):
	def cuts(data, sz):
		return sum((d + sz - 1) // sz - 1 for d in data)
	mx = max(data)
	return min(i + 1 + cuts(data, i + 1) for i in range(mx))


def main():
	T = int(input())
	results = []
	with cf.ProcessPoolExecutor(max_workers=8) as executor:
		for _ in range(T):
			D = int(input())
			P = [int(x) for x in input().split()]
			assert D == len(P)
			results.append(executor.submit(calc, P))
	for cs, result in enumerate(results):
		print('Case #{}: {}'.format(cs + 1, result.result()))


if __name__ == '__main__':
	main()
