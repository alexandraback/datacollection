import concurrent.futures as cf


def calc(data):
	standing, res = 0, 0
	for i, d in enumerate(data):
		if d == '0':
			continue
		if standing < i:
			new = i - standing
			standing += new
			res += new
		standing += int(d)
	return res
	

def main():
	T = int(input())
	results = []
	with cf.ProcessPoolExecutor(max_workers=8) as executor:
		for _ in range(T):
			l, data = input().split()
			assert len(data) == int(l) + 1
			results.append(executor.submit(calc, data))
	for cs, result in enumerate(results):
		print('Case #{}: {}'.format(cs + 1, result.result()))


if __name__ == '__main__':
	main()
