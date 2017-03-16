import concurrent.futures as cf
NAMES = ['RICHARD', 'GABRIEL']

def calc(X, R, C):
	if R > C:
		R, C = C, R
	if R * C % X:
		return NAMES[0]
	if X == 4:
		return NAMES[0 if R < 3 or C < 4 else 1]
	elif X == 3:
		return NAMES[0 if R < 2 else 1]
	return NAMES[1]
	

def main():
	T = int(input())
	results = []
	with cf.ProcessPoolExecutor(max_workers=8) as executor:
		for _ in range(T):
			X, R, C = [int(x) for x in input().split()]
			results.append(executor.submit(calc, X, R, C))
	for cs, result in enumerate(results):
		print('Case #{}: {}'.format(cs + 1, result.result()))


if __name__ == '__main__':
	main()
